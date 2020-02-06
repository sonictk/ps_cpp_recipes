/**
 * @file   main.js
 * @brief  Contains the logic for the CEP panel itself.
 */
var globalCSInterface = new CSInterface();

var DONE_CSXS_EVENT_ID = "com.examples.exportlayers.doneevent";


// Listen for events from the C++ plug-in.
globalCSInterface.addEventListener(DONE_CSXS_EVENT_ID,
                                   function(event) {
                                       AlertDialog(event.data);
                                       return;
                                   });


function AlertDialog(msg) {
    globalCSInterface.evalScript("alert(\"" + msg + "\");");

    return;
}


function ExportLayersCB() {
    globalCSInterface.evalScript("ESPSExportLayers();");

    return;
}


function ClosePanelCB() {
    globalCSInterface.closeExtension();

    return;
}


btnAccept.onclick = ExportLayersCB;
btnClose.onclick = ClosePanelCB;


// NOTE: We only need to do this because for some reason, trying to register the
// event listener for CSXS events in the C++ plugin fails when tying it to the
// kSPInterfaceStartupSelector; only registering that event listener _after_
// the PS UI is fully loaded seems to work, even though ``PlugPlugOwl.dll`` should
// have been loaded during the startup procedure itself.
globalCSInterface.evalScript("ESPSActivateAutomationPlugin();");
