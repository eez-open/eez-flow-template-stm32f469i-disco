/**
 * @callback RenameFile
 * @param {string} fileSrcRelativePath
 * @param {string} fileDstRelativePath
 * @returns {Promise<void>}
 */

/**
 * @callback ReplaceInFile
 * @param {string} fileRelativePath
 * @param {string} searchValue
 * @param {string} newValue
 * @returns {Promise<void>}
 */

/**
 * @typedef {Object} WizardContext
 * @property {string} projectDirPath
 * @property {string} projectName
 * @property {RenameFile} renameFile
 * @property {ReplaceInFile} replaceInFile
 */

/**
 * @param {WizardContext} context
 */
async function postProcessing(context) {
    await context.replaceInFile("Src/CMakeLists.txt", "eez-flow-template-sdl", context.projectName);

    await context.replaceInFile("README.md", "{{projectDirPath}}", context.projectDirPath);
    await context.replaceInFile("README.md", "{{projectName}}", context.projectName);

    await context.replaceInFile(".cproject", "{{projectName}}", context.projectName);
    await context.replaceInFile(".project", "{{projectName}}", context.projectName);

    await context.renameFile("eez-flow-template-stm32f469i-disco.ioc", context.projectName + ".ioc");
    await context.replaceInFile(context.projectName + ".ioc", "{{projectName}}", context.projectName);

    await context.renameFile("Src/eez-flow-template-stm32f469i-disco.eez-project", "Src/" + context.projectName + ".eez-project");

    await context.replaceInFile("Src/firmware.cpp", "{{projectName}}", context.projectName);

    await context.replaceInFile("Src/gui/hooks.cpp", "{{projectName}}", context.projectName);

    await context.replaceInFile("Src/platform/simulator/simulator.eez-project", "{{projectName}}", context.projectName);

    await context.replaceInFile("Src/platform/simulator/emscripten/index.html", "{{projectName}}", context.projectName);

    await context.replaceInFile("Src/platform/simulator/win32/icon.rc", "{{projectName}}", context.projectName);

    await context.replaceInFile("template/manifest.json", "{{projectName}}", context.projectName);
}

module.exports = postProcessing;
