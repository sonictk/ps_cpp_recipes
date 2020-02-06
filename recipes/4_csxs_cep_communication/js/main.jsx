/**
 * @file   main.jsx
 * @brief  Contains the logic for interfacing with Photoshop's JSX engine. The functions
 *         defined here are called by the front-end panel's JS and executed asynchronously.
 */
var globalPSApp = app; // type: Application


var EXPORT_LAYERS_CSXS_EVENT_ID = "com.examples.exportlayers.exportlayersevent";
var TUTORAL_CSXS_CEP_COMMUNICATION_UUID = "8a166f73-7984-4f69-a5d3-bb02d981adea";


function ESPSExportLayers() {
    // The library might not exist in some Photoshop versions.
    try {
        var xLib = new ExternalObject("lib:\PlugPlugExternalObject");
    } catch (e) {
        alert(e);
        return;
    }

    if (xLib) {
        var eventObj = new CSXSEvent();
        eventObj.type = EXPORT_LAYERS_CSXS_EVENT_ID;
        eventObj.data = true;
        eventObj.dispatch();
        return;
    }
    return;
}


function ESPSActivateAutomationPlugin() {
    var idPlugin = stringIDToTypeID(TUTORAL_CSXS_CEP_COMMUNICATION_UUID);
    executeAction(idPlugin, undefined, DialogModes.NO);

    return;
}
