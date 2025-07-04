--- @meta

-- This file is autogenerated. Do not edit this file manually. Your changes will be ignored.
-- More information: https://github.com/MWSE/MWSE/tree/master/docs

--- A core game object used for storing both active and non-dynamic gameplay data.
--- @class tes3dataHandler
--- @field backgroundThread number *Read-only*. A Windows handle to the background processing thread.
--- @field backgroundThreadId number *Read-only*. The thread ID for the background processing thread.
--- @field backgroundThreadRunning boolean *Read-only*. Access to the running state for the background processing thread.
--- @field cellChanged boolean *Read-only*. A flag set for the frame that the player has changed cells.
--- @field centralGridX number *Read-only*. The position of the origin horizontal grid coordinate.
--- @field centralGridY number *Read-only*. The position of the origin longitudinal grid coordinate.
--- @field currentAmbientWaterSound tes3sound Access to the current ambient water sound.
--- @field currentCell tes3cell *Read-only*. Access to the cell that the player is currently in.
--- @field currentInteriorCell tes3cell *Read-only*. Access to the current interior cell, if the player is in an interior.
--- @field dontThreadLoad boolean Access to dontThreadLoad setting.
--- @field exteriorCells tes3dataHandlerExteriorCellData[] *Read-only*. A table of nine [`tes3cellExteriorData`](https://mwse.github.io/MWSE/types/tes3cellExteriorData/) objects for all loaded exterior cells.
--- @field lastExteriorCell tes3cell *Read-only*. Access to the last visited exterior cell.
--- @field lowestZInCurrentCell number *Read-only*. The Z coordinate of the lowest point in the current cell, which is the bottom of the bounding box of the lowest object. Only valid for interiors.
--- 
--- This is used by the engine to check for the player falling out of bounds.
--- @field mainThread number *Read-only*. A Windows handle to the main execution thread.
--- @field mainThreadId number *Read-only*. The thread ID for the main execution thread.
--- @field nonDynamicData tes3nonDynamicData *Read-only*. A child structure where core game objects are held.
--- @field suppressThreadLoad boolean Access to suppressThreadLoad setting.
--- @field threadSleepTime number *Read-only*. No description yet available.
--- @field useCellTransitionFader boolean An engine flag that controls if there is a fade in/out between cells.
--- @field worldLandscapeRoot niBSAnimationNode|niBSParticleNode|niBillboardNode|niCollisionSwitch|niNode|niSortAdjustNode|niSwitchNode *Read-only*. Access to the root of the scene graph of all the currently loaded terrain. It's nine cells in total when the player is in exterior cell. While the player is in interior cell this node is culled.
--- @field worldObjectRoot niBSAnimationNode|niBSParticleNode|niBillboardNode|niCollisionSwitch|niNode|niSortAdjustNode|niSwitchNode *Read-only*. Access to the root of the scene graph containing all the static objects, and lights that can't be picked up. In addition, the player's scene graph is a child node of this root node.
--- @field worldPickObjectRoot niBSAnimationNode|niBSParticleNode|niBillboardNode|niCollisionSwitch|niNode|niSortAdjustNode|niSwitchNode *Read-only*. Access to the root of the scene graph containing all the objects that can be interacted with (NPCs, items, harvestable plants, activators, doors...), but also some objects that are only rendered in the Construction Set such as sound emmiting activator objects with EditorMarker.NIF mesh.
tes3dataHandler = {}

--- The current cell buffer sizes, as determined by Morrowind.ini.
--- @return number exteriorBufferSize No description yet available.
--- @return number interiorBufferSize No description yet available.
function tes3dataHandler:getCellBufferSizes() end

--- No description yet available.
--- @param params tes3dataHandler.updateCollisionGroupsForActiveCells.params This table accepts the following values:
--- 
--- `force?`: boolean — *Default*: `true`. No description yet available.
--- 
--- `isResettingData?`: boolean — *Default*: `false`. No description yet available.
--- 
--- `resetCollisionGroups?`: boolean — *Default*: `true`. No description yet available.
function tes3dataHandler:updateCollisionGroupsForActiveCells(params) end

---Table parameter definitions for `tes3dataHandler.updateCollisionGroupsForActiveCells`.
--- @class tes3dataHandler.updateCollisionGroupsForActiveCells.params
--- @field force? boolean *Default*: `true`. No description yet available.
--- @field isResettingData? boolean *Default*: `false`. No description yet available.
--- @field resetCollisionGroups? boolean *Default*: `true`. No description yet available.

--- Updates dynamic lights that affect exterior terrain and reference in exterior cells.
function tes3dataHandler:updateLightingForExteriorCells() end

