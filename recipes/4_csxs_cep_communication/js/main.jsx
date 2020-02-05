/**
 * @file   main.jsx
 * @brief  Contains the logic for interfacing with Photoshop's JSX engine. The functions
 *         defined here are called by the front-end panel's JS and executed asynchronously.
 */
var globalPSApp = app; // type: Application


var EXPORT_LAYERS_CSXS_EVENT_ID = "com.examples.exportlayers.exportlayers";


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
        eventObj.data = filename;
        eventObj.dispatch();

        return;
    }

    return;
}


function ESPSActivateAutomationPlugin() {
    var idPlugin = stringIDToTypeID("CSXSCEPCommunicationTutorial");
    executeAction(idPlugin, undefined, DialogModes.NO);

    return;
}
