#include <imgui.cpp> // NOTE: (sonictk) Must be included before ``imgui_internal.h``.
#include <imconfig.h>
#include <imgui_internal.h>
#include <imstb_rectpack.h>
#include <imstb_textedit.h>
#include <imstb_truetype.h>
#include <imgui_draw.cpp>
#include <imgui_widgets.cpp>

#include <imgui_impl_win32.cpp>
#include <imgui_impl_dx11.cpp>
#include <imgui_demo.cpp>

#include <d3d11.h>

#define GUI_WNDCLASS_NAME "PhotoshopTutorialImGuiWindow"
#define GUI_WNDTTILE "Photoshop Tutorial ImGui Window"

static int gGUIWidth = 0;
static int gGUIHeight = 0;

static ImVec2 gImGuiWndSize = ImVec2(0, 0);
static ImVec2 gImGuiWndPos = ImVec2(0, 0);

static HWND gGUIWndHwnd = NULL;
static HINSTANCE gGUIhInst = NULL;

static ID3D11Device *gD3D11Device = NULL;
static ID3D11DeviceContext *gD3D11DeviceContext = NULL;
static IDXGISwapChain *gD3D11SwapChain = NULL;
static ID3D11RenderTargetView *gD3D11MainRTV = NULL;

static float gD3D11ClearColor[4] = {0.0f, 1.0f, 0.0f, 1.0f};


void CreateD3D11RenderTarget()
{
	ID3D11Texture2D* pBackBuffer;
	gD3D11SwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
	gD3D11Device->CreateRenderTargetView(pBackBuffer, NULL, &gD3D11MainRTV);
	pBackBuffer->Release();

	return;
}


bool CreateD3D11Device(HWND hWnd)
{
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 2;
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	UINT createDeviceFlags = 0;
	D3D_FEATURE_LEVEL featureLevel;
	const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
	if (D3D11CreateDeviceAndSwapChain(NULL,
									  D3D_DRIVER_TYPE_HARDWARE,
									  NULL,
									  createDeviceFlags,
									  featureLevelArray,
									  2,
									  D3D11_SDK_VERSION,
									  &sd,
									  &gD3D11SwapChain,
									  &gD3D11Device,
									  &featureLevel,
									  &gD3D11DeviceContext) != S_OK) {
		return false;
	}

	CreateD3D11RenderTarget();
	return true;
}


void CleanupD3D11RenderTarget()
{
	if (gD3D11MainRTV != NULL) {
		gD3D11MainRTV->Release();
		gD3D11MainRTV = NULL;
	}
	return;
}


void CleanupD3D11Device()
{
	CleanupD3D11RenderTarget();
	if (gD3D11SwapChain != NULL) { gD3D11SwapChain->Release(); gD3D11SwapChain = NULL; }
	if (gD3D11DeviceContext) { gD3D11DeviceContext->Release(); gD3D11DeviceContext = NULL; }
	if (gD3D11Device) { gD3D11Device->Release(); gD3D11Device = NULL; }
	return;
}


// Win32 message handler
LRESULT WINAPI GUIWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (gD3D11Device != NULL && wParam != SIZE_MINIMIZED)
		{
			CleanupD3D11RenderTarget();
			gD3D11SwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
			CreateD3D11RenderTarget();
		}
		return 0;
	case WM_CLOSE:
		// TODO: (yliangsiew) Show confirmation dialog.
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void displayFilterGUIWithResult(HWND parentPSWindow, GUIResult *uiResult)
{
	WNDCLASSEX windowClass;
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW|CS_VREDRAW;
	windowClass.lpfnWndProc = GUIWndProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = GetModuleHandle(NULL);
	windowClass.hIcon = LoadIcon(0, IDI_APPLICATION);
	windowClass.hCursor = LoadCursor(0, IDC_ARROW);
	windowClass.hbrBackground = NULL;
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = GUI_WNDCLASS_NAME;
	windowClass.hIconSm = NULL;
	RegisterClassEx(&windowClass);

	HMONITOR hMonitor = MonitorFromWindow(parentPSWindow, MONITOR_DEFAULTTONEAREST);
	MONITORINFOEX monitorInfo;
	ZeroMemory(&monitorInfo, sizeof(monitorInfo));
	monitorInfo.cbSize = sizeof(monitorInfo);
	BOOL bStat = GetMonitorInfo(hMonitor, &monitorInfo);
	assert(bStat != 0);

	gGUIWidth = monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left;
	gGUIHeight = monitorInfo.rcMonitor.bottom - monitorInfo.rcMonitor.top;

	// NOTE: (sonictk) Because CreateWindow() also includes the menu bar and the
	// border in the width/height passed in, we get the _real_ dimensions that
	// should be passed in here by letting Windows calculate what they should be
	// so that we can have proper width/height for the client area we're drawing in.
	RECT clientRect = {0, 0, gGUIWidth, gGUIHeight};
	BOOL  status;
	status = AdjustWindowRectEx(&clientRect, WS_POPUP, FALSE, WS_EX_LAYERED);
	assert(status != 0);

	HWND guiHWnd = CreateWindowEx(WS_EX_LAYERED,
								  GUI_WNDCLASS_NAME,
								  GUI_WNDTTILE,
								  WS_POPUP,
								  monitorInfo.rcMonitor.left,
								  monitorInfo.rcMonitor.top,
								  clientRect.right - clientRect.left,
								  clientRect.bottom - clientRect.top,
								  parentPSWindow,
								  NULL, // NOTE: (sonictk) No menu or child window
								  windowClass.hInstance, // NOTE: (sonictk) Module associated with this window
								  NULL); // NOTE: (sonictk) No additional data needed
	assert(guiHWnd != NULL);

	// NOTE: (yliangsiew) Fake transparency for the window
	SetLayeredWindowAttributes(guiHWnd, RGB(0,255,0), 0, LWA_COLORKEY);

	if (!CreateD3D11Device(guiHWnd)) {
		CleanupD3D11Device();
		UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
		return;
	}

	// NOTE: (sonictk) Show the window using the flag specified by the program that
	// started the application, and then send the app a WM_PAINT message.
	ShowWindow(guiHWnd, SW_SHOWDEFAULT);
	status = UpdateWindow(guiHWnd);
	assert(status != 0);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& imGuiIO = ImGui::GetIO(); (void)imGuiIO;
	ImGui::StyleColorsLight();

	ImGui_ImplWin32_Init(guiHWnd);
	ImGui_ImplDX11_Init(gD3D11Device, gD3D11DeviceContext);

	static bool shouldShowWindow = true;

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}

		// NOTE: (yliangsiew): For some reason, any interaction
		// with imgui widgets of any sort will cause Photoshop to crash later on
		// after both filters have returned. Something is setting some function pointer
		// to 0, and I don't know what. Therefore, this crazy workaround is in-place that
		// tells the window to close instead of exiting this render loop, mimicking an
		// Alt-F4 interaction.
		if (!shouldShowWindow) {
			PostMessage(guiHWnd, WM_CLOSE, 0, 0);
		}

		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		{
			ImGui::SetNextWindowSize(gImGuiWndSize, ImGuiCond_Always);

			static const ImGuiWindowFlags imGuiWndFlags = ImGuiWindowFlags_AlwaysAutoResize;

			if (shouldShowWindow) {
				ImGui::Begin("Export Options", NULL, imGuiWndFlags);

				ImGui::End();
			}

		}
		ImGui::Render();

		gD3D11DeviceContext->OMSetRenderTargets(1, &gD3D11MainRTV, NULL);
		gD3D11DeviceContext->ClearRenderTargetView(gD3D11MainRTV, gD3D11ClearColor);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

		gD3D11SwapChain->Present(1, 0);
	}

	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	CleanupD3D11Device();
	DestroyWindow(guiHWnd);
	UnregisterClassA(windowClass.lpszClassName, windowClass.hInstance);

	return;
}
