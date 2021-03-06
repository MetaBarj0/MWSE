tes3mobileNPC
====================================================================================================

A mobile object for an NPC.

Properties
----------------------------------------------------------------------------------------------------

`acrobatics`_ (`tes3skillStatistic`_)
    Direct access to the NPC's acrobatics skill statistic.

`actionBeforeCombat`_ (`tes3actionData`_)
    Action data stored before the actor entered combat.

`actionData`_ (`tes3actionData`_)
    Current action data. Pre-combat action data is stored in the actionBeforeCombat property.

`activeAI`_ (`boolean`_)
    Friendly access to the actor's flag that controls if AI is active.

`activeMagicEffectCount`_ (`number`_)
    The number of active magic effects currently operating on the actor.

`activeMagicEffects`_ (`tes3activeMagicEffect`_)
    The first active magic effect on the actor, from which all others can be accessed.

`actorType`_ (`number`_)
    The type of the mobile actor. 0 is a creature, 1 is an NPC, 2 is the player.

`agility`_ (`tes3statistic`_)
    Direct access to the actor's agility attribute statistic.

`aiPlanner`_ (`tes3aiPlanner`_)
    Access to the mobile's AI planner and AI package information.

`alarm`_ (`number`_)
    The actor's alarm AI value.

`alchemy`_ (`tes3skillStatistic`_)
    Direct access to the NPC's alchemy skill statistic.

`alteration`_ (`tes3skillStatistic`_)
    Direct access to the NPC's alteration skill statistic.

`animationData`_ (`tes3actorAnimationData`_)
    No description available.

`armorer`_ (`tes3skillStatistic`_)
    Direct access to the NPC's armorer skill statistic.

`athletics`_ (`tes3skillStatistic`_)
    Direct access to the NPC's athletics skill statistic.

`attackBonus`_ (`number`_)
    Direct access to the actor's attack bonus effect attribute.

`attacked`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor has been attacked.

`attributes`_ (`table`_)
    Access to a table of 8 tes3statistic objects for the actor's attributes.

`axe`_ (`tes3skillStatistic`_)
    Direct access to the NPC's axe skill statistic.

`barterGold`_ (`number`_)
    The current amount of gold that the actor has access to for bartering.

`blind`_ (`number`_)
    Direct access to the actor's blind effect attribute.

`block`_ (`tes3skillStatistic`_)
    Direct access to the NPC's block skill statistic.

`bluntWeapon`_ (`tes3skillStatistic`_)
    Direct access to the NPC's blunt weapon skill statistic.

`boundSize`_ (`tes3vector3`_)
    A vector that shows the size of the bounding box in each direction.

`cell`_ (`tes3cell`_)
    Fetches the cell that the actor is in.

`cellX`_ (`number`_)
    The X grid coordinate of the cell the mobile is in.

`cellY`_ (`number`_)
    The Y grid coordinate of the cell the mobile is in.

`chameleon`_ (`number`_)
    Direct access to the actor's chameleon effect attribute.

`collidingReference`_ (`tes3reference`_)
    The reference that the mobile has collided with this frame.

`conjuration`_ (`tes3skillStatistic`_)
    Direct access to the NPC's conjuration skill statistic.

`corpseHourstamp`_ (`number`_)
    No description available.

`currentEnchantedItem`_ (`tes3equipmentStack`_)
    The currently equipped enchanted item that the actor will use.

`currentSpell`_ (`tes3spell`_)
    The currently equipped spell that the actor will use.

`destruction`_ (`tes3skillStatistic`_)
    Direct access to the NPC's destruction skill statistic.

`effectAttributes`_ (`table`_)
    Access to a table of 24 numbers for the actor's effect attributes.

`enchant`_ (`tes3skillStatistic`_)
    Direct access to the NPC's enchant skill statistic.

`encumbrance`_ (`tes3statistic`_)
    Access to the actor's encumbrance statistic.

`endurance`_ (`tes3statistic`_)
    Direct access to the actor's endurance attribute statistic.

`fatigue`_ (`tes3statistic`_)
    Access to the actor's fatigue statistic.

`fight`_ (`number`_)
    The actor's fight AI value.

`flags`_ (`number`_)
    Access to the root mobile object flags, represented as an integer. Should not be accessed directly.

`flee`_ (`number`_)
    The actor's flee AI value.

`flySpeed`_ (`number`_)
    The calculated fly movement speed.

`forceJump`_ (`boolean`_)
    Toggle flag for if the NPC jumps.

`forceMoveJump`_ (`boolean`_)
    Toggle flag for if the NPC moves and jumps.

`forceRun`_ (`boolean`_)
    Toggle flag for if the NPC runs.

`forceSneak`_ (`boolean`_)
    Toggle flag for if the NPC sneaks.

`friendlyActors`_ (`tes3iterator`_)
    A collection of other tes3mobileActors that this actor considers friendly.

`greetDuration`_ (`number`_)
    No description available.

`greetTimer`_ (`number`_)
    No description available.

`handToHand`_ (`tes3skillStatistic`_)
    Direct access to the NPC's hand to hand skill statistic.

`health`_ (`tes3statistic`_)
    Access to the actor's health statistic.

`heavyArmor`_ (`tes3skillStatistic`_)
    Direct access to the NPC's heavy armor skill statistic.

`height`_ (`number`_)
    The height of the mobile above the ground.

`hello`_ (`number`_)
    The actor's hello AI value.

`holdBreathTime`_ (`number`_)
    No description available.

`hostileActors`_ (`tes3iterator`_)
    A collection of other tes3mobileActors that this actor considers hostile.

`idleAnim`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor is using their idle animation.

`illusion`_ (`tes3skillStatistic`_)
    Direct access to the NPC's illusion skill statistic.

`impulseVelocity`_ (`tes3vector3`_)
    A vector that represents the 3D acceleration of the object.

`inCombat`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor is in combat.

`intelligence`_ (`tes3statistic`_)
    Direct access to the actor's intelligence attribute statistic.

`invisibility`_ (`number`_)
    Direct access to the actor's invisibility effect attribute.

`isCrittable`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor can be crittically hit.

`isFlying`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is flying.

`isJumping`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is jumping.

`isMovingBack`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is moving backwards.

`isMovingForward`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is moving forwards.

`isMovingLeft`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is moving left.

`isMovingRight`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is moving right.

`isRunning`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is running.

`isSneaking`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is sneaking.

`isStartingJump`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor has started jumping.

`isSwimming`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is swimming.

`isTurningLeft`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is turning left.

`isTurningRight`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is turning right.

`isWalking`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is walking.

`jump`_ (`number`_)
    Direct access to the actor's jump effect attribute.

`lastGroundZ`_ (`number`_)
    No description available.

`levitate`_ (`number`_)
    Direct access to the actor's levitate effect attribute.

`lightArmor`_ (`tes3skillStatistic`_)
    Direct access to the NPC's light armor skill statistic.

`longBlade`_ (`tes3skillStatistic`_)
    Direct access to the NPC's long blade skill statistic.

`luck`_ (`tes3statistic`_)
    Direct access to the actor's luck attribute statistic.

`magicka`_ (`tes3statistic`_)
    Access to the actor's magicka statistic.

`magickaMultiplier`_ (`tes3statistic`_)
    Access to the actor's magicka multiplier statistic.

`marksman`_ (`tes3skillStatistic`_)
    Direct access to the NPC's marksman skill statistic.

`mediumArmor`_ (`tes3skillStatistic`_)
    Direct access to the NPC's medium armor skill statistic.

`mercantile`_ (`tes3skillStatistic`_)
    Direct access to the NPC's mercantile skill statistic.

`moveSpeed`_ (`number`_)
    The calculated base movement speed.

`movementFlags`_ (`number`_)
    Access to the root mobile object movement flags, represented as an integer. Should not be accessed directly.

`mysticism`_ (`tes3skillStatistic`_)
    Direct access to the NPC's mysticism skill statistic.

`nextActionWeight`_ (`number`_)
    No description available.

`object`_ (`tes3npcInstance`_)
    The actor object that maps to this mobile.

`objectType`_ (`number`_)
    The type of mobile object. Maps to values in tes3.objectType.

`paralyze`_ (`number`_)
    Direct access to the actor's paralyze effect attribute.

`personality`_ (`tes3statistic`_)
    Direct access to the actor's personality attribute statistic.

`position`_ (`tes3vector3`_)
    A vector that represents the 3D position of the object.

`prevMovementFlags`_ (`number`_)
    Access to the root mobile object movement flags from the previous frame, represented as an integer. Should not be accessed directly.

`readiedAmmo`_ (`tes3equipmentStack`_)
    The currently equipped ammo.

`readiedAmmoCount`_ (`number`_)
    The number of ammo equipped for the readied ammo.

`readiedShield`_ (`tes3equipmentStack`_)
    The currently equipped shield.

`readiedWeapon`_ (`tes3equipmentStack`_)
    The currently equipped weapon.

`reference`_ (`tes3reference`_)
    Access to the reference object for the mobile, if any.

`resistBlightDisease`_ (`number`_)
    Direct access to the actor's blight disease resistance effect attribute.

`resistCommonDisease`_ (`number`_)
    Direct access to the actor's common disease resistance effect attribute.

`resistCorprus`_ (`number`_)
    Direct access to the actor's corprus disease resistance effect attribute.

`resistFire`_ (`number`_)
    Direct access to the actor's fire resistance effect attribute.

`resistFrost`_ (`number`_)
    Direct access to the actor's frost resistance effect attribute.

`resistMagicka`_ (`number`_)
    Direct access to the actor's magicka resistance effect attribute.

`resistNormalWeapons`_ (`number`_)
    Direct access to the actor's normal weapon resistance effect attribute.

`resistParalysis`_ (`number`_)
    Direct access to the actor's paralysis resistance effect attribute.

`resistPoison`_ (`number`_)
    Direct access to the actor's poison resistance effect attribute.

`resistShock`_ (`number`_)
    Direct access to the actor's shock resistance effect attribute.

`restoration`_ (`tes3skillStatistic`_)
    Direct access to the NPC's restoration skill statistic.

`runSpeed`_ (`number`_)
    The calculated run movement speed.

`sanctuary`_ (`number`_)
    Direct access to the actor's sanctuary effect attribute.

`scanInterval`_ (`number`_)
    No description available.

`scanTimer`_ (`number`_)
    No description available.

`security`_ (`tes3skillStatistic`_)
    Direct access to the NPC's security skill statistic.

`shield`_ (`number`_)
    Direct access to the actor's shield effect attribute.

`shortBlade`_ (`tes3skillStatistic`_)
    Direct access to the NPC's short blade skill statistic.

`silence`_ (`number`_)
    Direct access to the actor's silence effect attribute.

`skills`_ (`table`_)
    An array-style table with access to the twenty seven NPC skill statistics.

`sneak`_ (`tes3skillStatistic`_)
    Direct access to the NPC's sneak skill statistic.

`sound`_ (`number`_)
    Direct access to the actor's sound effect attribute.

`spear`_ (`tes3skillStatistic`_)
    Direct access to the NPC's spear skill statistic.

`speechcraft`_ (`tes3skillStatistic`_)
    Direct access to the NPC's speechcraft skill statistic.

`speed`_ (`tes3statistic`_)
    Direct access to the actor's speed attribute statistic.

`spellReadied`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor has a spell readied.

`strength`_ (`tes3statistic`_)
    Direct access to the actor's strength attribute statistic.

`swiftSwim`_ (`number`_)
    Direct access to the actor's swift swim effect attribute.

`swimRunSpeed`_ (`number`_)
    The calculated swim movement speed while running.

`swimSpeed`_ (`number`_)
    The calculated swim movement speed.

`torchSlot`_ (`tes3equipmentStack`_)
    The currently equipped light.

`unarmored`_ (`tes3skillStatistic`_)
    Direct access to the NPC's unarmored skill statistic.

`underwater`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor is under water.

`velocity`_ (`tes3vector3`_)
    A vector that represents the 3D velocity of the object.

`walkSpeed`_ (`number`_)
    The calculated walk movement speed.

`waterBreathing`_ (`number`_)
    Direct access to the actor's water breathing effect attribute.

`waterWalking`_ (`number`_)
    Direct access to the actor's water walking effect attribute.

`weaponDrawn`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor has a weapon readied.

`werewolf`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor in werewolf form.

`width`_ (`number`_)
    No description available.

`willpower`_ (`tes3statistic`_)
    Direct access to the actor's willpower attribute statistic.

.. toctree::
    :hidden:

    tes3mobileNPC/acrobatics
    tes3mobileNPC/actionBeforeCombat
    tes3mobileNPC/actionData
    tes3mobileNPC/activeAI
    tes3mobileNPC/activeMagicEffectCount
    tes3mobileNPC/activeMagicEffects
    tes3mobileNPC/actorType
    tes3mobileNPC/agility
    tes3mobileNPC/aiPlanner
    tes3mobileNPC/alarm
    tes3mobileNPC/alchemy
    tes3mobileNPC/alteration
    tes3mobileNPC/animationData
    tes3mobileNPC/armorer
    tes3mobileNPC/athletics
    tes3mobileNPC/attackBonus
    tes3mobileNPC/attacked
    tes3mobileNPC/attributes
    tes3mobileNPC/axe
    tes3mobileNPC/barterGold
    tes3mobileNPC/blind
    tes3mobileNPC/block
    tes3mobileNPC/bluntWeapon
    tes3mobileNPC/boundSize
    tes3mobileNPC/cell
    tes3mobileNPC/cellX
    tes3mobileNPC/cellY
    tes3mobileNPC/chameleon
    tes3mobileNPC/collidingReference
    tes3mobileNPC/conjuration
    tes3mobileNPC/corpseHourstamp
    tes3mobileNPC/currentEnchantedItem
    tes3mobileNPC/currentSpell
    tes3mobileNPC/destruction
    tes3mobileNPC/effectAttributes
    tes3mobileNPC/enchant
    tes3mobileNPC/encumbrance
    tes3mobileNPC/endurance
    tes3mobileNPC/fatigue
    tes3mobileNPC/fight
    tes3mobileNPC/flags
    tes3mobileNPC/flee
    tes3mobileNPC/flySpeed
    tes3mobileNPC/forceJump
    tes3mobileNPC/forceMoveJump
    tes3mobileNPC/forceRun
    tes3mobileNPC/forceSneak
    tes3mobileNPC/friendlyActors
    tes3mobileNPC/greetDuration
    tes3mobileNPC/greetTimer
    tes3mobileNPC/handToHand
    tes3mobileNPC/health
    tes3mobileNPC/heavyArmor
    tes3mobileNPC/height
    tes3mobileNPC/hello
    tes3mobileNPC/holdBreathTime
    tes3mobileNPC/hostileActors
    tes3mobileNPC/idleAnim
    tes3mobileNPC/illusion
    tes3mobileNPC/impulseVelocity
    tes3mobileNPC/inCombat
    tes3mobileNPC/intelligence
    tes3mobileNPC/invisibility
    tes3mobileNPC/isCrittable
    tes3mobileNPC/isFlying
    tes3mobileNPC/isJumping
    tes3mobileNPC/isMovingBack
    tes3mobileNPC/isMovingForward
    tes3mobileNPC/isMovingLeft
    tes3mobileNPC/isMovingRight
    tes3mobileNPC/isRunning
    tes3mobileNPC/isSneaking
    tes3mobileNPC/isStartingJump
    tes3mobileNPC/isSwimming
    tes3mobileNPC/isTurningLeft
    tes3mobileNPC/isTurningRight
    tes3mobileNPC/isWalking
    tes3mobileNPC/jump
    tes3mobileNPC/lastGroundZ
    tes3mobileNPC/levitate
    tes3mobileNPC/lightArmor
    tes3mobileNPC/longBlade
    tes3mobileNPC/luck
    tes3mobileNPC/magicka
    tes3mobileNPC/magickaMultiplier
    tes3mobileNPC/marksman
    tes3mobileNPC/mediumArmor
    tes3mobileNPC/mercantile
    tes3mobileNPC/moveSpeed
    tes3mobileNPC/movementFlags
    tes3mobileNPC/mysticism
    tes3mobileNPC/nextActionWeight
    tes3mobileNPC/object
    tes3mobileNPC/objectType
    tes3mobileNPC/paralyze
    tes3mobileNPC/personality
    tes3mobileNPC/position
    tes3mobileNPC/prevMovementFlags
    tes3mobileNPC/readiedAmmo
    tes3mobileNPC/readiedAmmoCount
    tes3mobileNPC/readiedShield
    tes3mobileNPC/readiedWeapon
    tes3mobileNPC/reference
    tes3mobileNPC/resistBlightDisease
    tes3mobileNPC/resistCommonDisease
    tes3mobileNPC/resistCorprus
    tes3mobileNPC/resistFire
    tes3mobileNPC/resistFrost
    tes3mobileNPC/resistMagicka
    tes3mobileNPC/resistNormalWeapons
    tes3mobileNPC/resistParalysis
    tes3mobileNPC/resistPoison
    tes3mobileNPC/resistShock
    tes3mobileNPC/restoration
    tes3mobileNPC/runSpeed
    tes3mobileNPC/sanctuary
    tes3mobileNPC/scanInterval
    tes3mobileNPC/scanTimer
    tes3mobileNPC/security
    tes3mobileNPC/shield
    tes3mobileNPC/shortBlade
    tes3mobileNPC/silence
    tes3mobileNPC/skills
    tes3mobileNPC/sneak
    tes3mobileNPC/sound
    tes3mobileNPC/spear
    tes3mobileNPC/speechcraft
    tes3mobileNPC/speed
    tes3mobileNPC/spellReadied
    tes3mobileNPC/strength
    tes3mobileNPC/swiftSwim
    tes3mobileNPC/swimRunSpeed
    tes3mobileNPC/swimSpeed
    tes3mobileNPC/torchSlot
    tes3mobileNPC/unarmored
    tes3mobileNPC/underwater
    tes3mobileNPC/velocity
    tes3mobileNPC/walkSpeed
    tes3mobileNPC/waterBreathing
    tes3mobileNPC/waterWalking
    tes3mobileNPC/weaponDrawn
    tes3mobileNPC/werewolf
    tes3mobileNPC/width
    tes3mobileNPC/willpower

.. _`acrobatics`: tes3mobileNPC/acrobatics.html
.. _`actionBeforeCombat`: tes3mobileNPC/actionBeforeCombat.html
.. _`actionData`: tes3mobileNPC/actionData.html
.. _`activeAI`: tes3mobileNPC/activeAI.html
.. _`activeMagicEffectCount`: tes3mobileNPC/activeMagicEffectCount.html
.. _`activeMagicEffects`: tes3mobileNPC/activeMagicEffects.html
.. _`actorType`: tes3mobileNPC/actorType.html
.. _`agility`: tes3mobileNPC/agility.html
.. _`aiPlanner`: tes3mobileNPC/aiPlanner.html
.. _`alarm`: tes3mobileNPC/alarm.html
.. _`alchemy`: tes3mobileNPC/alchemy.html
.. _`alteration`: tes3mobileNPC/alteration.html
.. _`animationData`: tes3mobileNPC/animationData.html
.. _`armorer`: tes3mobileNPC/armorer.html
.. _`athletics`: tes3mobileNPC/athletics.html
.. _`attackBonus`: tes3mobileNPC/attackBonus.html
.. _`attacked`: tes3mobileNPC/attacked.html
.. _`attributes`: tes3mobileNPC/attributes.html
.. _`axe`: tes3mobileNPC/axe.html
.. _`barterGold`: tes3mobileNPC/barterGold.html
.. _`blind`: tes3mobileNPC/blind.html
.. _`block`: tes3mobileNPC/block.html
.. _`bluntWeapon`: tes3mobileNPC/bluntWeapon.html
.. _`boundSize`: tes3mobileNPC/boundSize.html
.. _`cell`: tes3mobileNPC/cell.html
.. _`cellX`: tes3mobileNPC/cellX.html
.. _`cellY`: tes3mobileNPC/cellY.html
.. _`chameleon`: tes3mobileNPC/chameleon.html
.. _`collidingReference`: tes3mobileNPC/collidingReference.html
.. _`conjuration`: tes3mobileNPC/conjuration.html
.. _`corpseHourstamp`: tes3mobileNPC/corpseHourstamp.html
.. _`currentEnchantedItem`: tes3mobileNPC/currentEnchantedItem.html
.. _`currentSpell`: tes3mobileNPC/currentSpell.html
.. _`destruction`: tes3mobileNPC/destruction.html
.. _`effectAttributes`: tes3mobileNPC/effectAttributes.html
.. _`enchant`: tes3mobileNPC/enchant.html
.. _`encumbrance`: tes3mobileNPC/encumbrance.html
.. _`endurance`: tes3mobileNPC/endurance.html
.. _`fatigue`: tes3mobileNPC/fatigue.html
.. _`fight`: tes3mobileNPC/fight.html
.. _`flags`: tes3mobileNPC/flags.html
.. _`flee`: tes3mobileNPC/flee.html
.. _`flySpeed`: tes3mobileNPC/flySpeed.html
.. _`forceJump`: tes3mobileNPC/forceJump.html
.. _`forceMoveJump`: tes3mobileNPC/forceMoveJump.html
.. _`forceRun`: tes3mobileNPC/forceRun.html
.. _`forceSneak`: tes3mobileNPC/forceSneak.html
.. _`friendlyActors`: tes3mobileNPC/friendlyActors.html
.. _`greetDuration`: tes3mobileNPC/greetDuration.html
.. _`greetTimer`: tes3mobileNPC/greetTimer.html
.. _`handToHand`: tes3mobileNPC/handToHand.html
.. _`health`: tes3mobileNPC/health.html
.. _`heavyArmor`: tes3mobileNPC/heavyArmor.html
.. _`height`: tes3mobileNPC/height.html
.. _`hello`: tes3mobileNPC/hello.html
.. _`holdBreathTime`: tes3mobileNPC/holdBreathTime.html
.. _`hostileActors`: tes3mobileNPC/hostileActors.html
.. _`idleAnim`: tes3mobileNPC/idleAnim.html
.. _`illusion`: tes3mobileNPC/illusion.html
.. _`impulseVelocity`: tes3mobileNPC/impulseVelocity.html
.. _`inCombat`: tes3mobileNPC/inCombat.html
.. _`intelligence`: tes3mobileNPC/intelligence.html
.. _`invisibility`: tes3mobileNPC/invisibility.html
.. _`isCrittable`: tes3mobileNPC/isCrittable.html
.. _`isFlying`: tes3mobileNPC/isFlying.html
.. _`isJumping`: tes3mobileNPC/isJumping.html
.. _`isMovingBack`: tes3mobileNPC/isMovingBack.html
.. _`isMovingForward`: tes3mobileNPC/isMovingForward.html
.. _`isMovingLeft`: tes3mobileNPC/isMovingLeft.html
.. _`isMovingRight`: tes3mobileNPC/isMovingRight.html
.. _`isRunning`: tes3mobileNPC/isRunning.html
.. _`isSneaking`: tes3mobileNPC/isSneaking.html
.. _`isStartingJump`: tes3mobileNPC/isStartingJump.html
.. _`isSwimming`: tes3mobileNPC/isSwimming.html
.. _`isTurningLeft`: tes3mobileNPC/isTurningLeft.html
.. _`isTurningRight`: tes3mobileNPC/isTurningRight.html
.. _`isWalking`: tes3mobileNPC/isWalking.html
.. _`jump`: tes3mobileNPC/jump.html
.. _`lastGroundZ`: tes3mobileNPC/lastGroundZ.html
.. _`levitate`: tes3mobileNPC/levitate.html
.. _`lightArmor`: tes3mobileNPC/lightArmor.html
.. _`longBlade`: tes3mobileNPC/longBlade.html
.. _`luck`: tes3mobileNPC/luck.html
.. _`magicka`: tes3mobileNPC/magicka.html
.. _`magickaMultiplier`: tes3mobileNPC/magickaMultiplier.html
.. _`marksman`: tes3mobileNPC/marksman.html
.. _`mediumArmor`: tes3mobileNPC/mediumArmor.html
.. _`mercantile`: tes3mobileNPC/mercantile.html
.. _`moveSpeed`: tes3mobileNPC/moveSpeed.html
.. _`movementFlags`: tes3mobileNPC/movementFlags.html
.. _`mysticism`: tes3mobileNPC/mysticism.html
.. _`nextActionWeight`: tes3mobileNPC/nextActionWeight.html
.. _`object`: tes3mobileNPC/object.html
.. _`objectType`: tes3mobileNPC/objectType.html
.. _`paralyze`: tes3mobileNPC/paralyze.html
.. _`personality`: tes3mobileNPC/personality.html
.. _`position`: tes3mobileNPC/position.html
.. _`prevMovementFlags`: tes3mobileNPC/prevMovementFlags.html
.. _`readiedAmmo`: tes3mobileNPC/readiedAmmo.html
.. _`readiedAmmoCount`: tes3mobileNPC/readiedAmmoCount.html
.. _`readiedShield`: tes3mobileNPC/readiedShield.html
.. _`readiedWeapon`: tes3mobileNPC/readiedWeapon.html
.. _`reference`: tes3mobileNPC/reference.html
.. _`resistBlightDisease`: tes3mobileNPC/resistBlightDisease.html
.. _`resistCommonDisease`: tes3mobileNPC/resistCommonDisease.html
.. _`resistCorprus`: tes3mobileNPC/resistCorprus.html
.. _`resistFire`: tes3mobileNPC/resistFire.html
.. _`resistFrost`: tes3mobileNPC/resistFrost.html
.. _`resistMagicka`: tes3mobileNPC/resistMagicka.html
.. _`resistNormalWeapons`: tes3mobileNPC/resistNormalWeapons.html
.. _`resistParalysis`: tes3mobileNPC/resistParalysis.html
.. _`resistPoison`: tes3mobileNPC/resistPoison.html
.. _`resistShock`: tes3mobileNPC/resistShock.html
.. _`restoration`: tes3mobileNPC/restoration.html
.. _`runSpeed`: tes3mobileNPC/runSpeed.html
.. _`sanctuary`: tes3mobileNPC/sanctuary.html
.. _`scanInterval`: tes3mobileNPC/scanInterval.html
.. _`scanTimer`: tes3mobileNPC/scanTimer.html
.. _`security`: tes3mobileNPC/security.html
.. _`shield`: tes3mobileNPC/shield.html
.. _`shortBlade`: tes3mobileNPC/shortBlade.html
.. _`silence`: tes3mobileNPC/silence.html
.. _`skills`: tes3mobileNPC/skills.html
.. _`sneak`: tes3mobileNPC/sneak.html
.. _`sound`: tes3mobileNPC/sound.html
.. _`spear`: tes3mobileNPC/spear.html
.. _`speechcraft`: tes3mobileNPC/speechcraft.html
.. _`speed`: tes3mobileNPC/speed.html
.. _`spellReadied`: tes3mobileNPC/spellReadied.html
.. _`strength`: tes3mobileNPC/strength.html
.. _`swiftSwim`: tes3mobileNPC/swiftSwim.html
.. _`swimRunSpeed`: tes3mobileNPC/swimRunSpeed.html
.. _`swimSpeed`: tes3mobileNPC/swimSpeed.html
.. _`torchSlot`: tes3mobileNPC/torchSlot.html
.. _`unarmored`: tes3mobileNPC/unarmored.html
.. _`underwater`: tes3mobileNPC/underwater.html
.. _`velocity`: tes3mobileNPC/velocity.html
.. _`walkSpeed`: tes3mobileNPC/walkSpeed.html
.. _`waterBreathing`: tes3mobileNPC/waterBreathing.html
.. _`waterWalking`: tes3mobileNPC/waterWalking.html
.. _`weaponDrawn`: tes3mobileNPC/weaponDrawn.html
.. _`werewolf`: tes3mobileNPC/werewolf.html
.. _`width`: tes3mobileNPC/width.html
.. _`willpower`: tes3mobileNPC/willpower.html

Methods
----------------------------------------------------------------------------------------------------

`applyHealthDamage`_ (`boolean`_)
    Damages the actor.

`equip`_ (`boolean`_)
    Equips an item, optionally adding the item if needed.

`getSkillStatistic`_ (`tes3skillStatistic`_)
    Fetches the statistic object of a skill with a given index. This converts to the limited options available for creatures.

`getSkillValue`_ (`number`_)
    Fetches the current value of a skill with a given index. This converts to the limited options available for creatures.

`hasFreeAction`_ (`boolean`_)
    If true, the actor isn't paralyzed, dead, stunned, or otherwise unable to take action.

`isAffectedByObject`_ (`boolean`_)
    Determines if the actor is currently being affected by a given alchemy, enchantment, or spell.

`startCombat`_
    Forces the actor into combat with another actor.

`startDialogue`_
    Starts dialogue with this actor for the player.

`stopCombat`_
    Ends combat for the actor.

`unequip`_ (`boolean`_)
    Unequips one or more items from the actor.

.. toctree::
    :hidden:

    tes3mobileNPC/applyHealthDamage
    tes3mobileNPC/equip
    tes3mobileNPC/getSkillStatistic
    tes3mobileNPC/getSkillValue
    tes3mobileNPC/hasFreeAction
    tes3mobileNPC/isAffectedByObject
    tes3mobileNPC/startCombat
    tes3mobileNPC/startDialogue
    tes3mobileNPC/stopCombat
    tes3mobileNPC/unequip

.. _`applyHealthDamage`: tes3mobileNPC/applyHealthDamage.html
.. _`equip`: tes3mobileNPC/equip.html
.. _`getSkillStatistic`: tes3mobileNPC/getSkillStatistic.html
.. _`getSkillValue`: tes3mobileNPC/getSkillValue.html
.. _`hasFreeAction`: tes3mobileNPC/hasFreeAction.html
.. _`isAffectedByObject`: tes3mobileNPC/isAffectedByObject.html
.. _`startCombat`: tes3mobileNPC/startCombat.html
.. _`startDialogue`: tes3mobileNPC/startDialogue.html
.. _`stopCombat`: tes3mobileNPC/stopCombat.html
.. _`unequip`: tes3mobileNPC/unequip.html

.. _`tes3creature`: ../../lua/type/tes3creature.html
.. _`niObject`: ../../lua/type/niObject.html
.. _`tes3book`: ../../lua/type/tes3book.html
.. _`niAlphaProperty`: ../../lua/type/niAlphaProperty.html
.. _`tes3spell`: ../../lua/type/tes3spell.html
.. _`tes3inputConfig`: ../../lua/type/tes3inputConfig.html
.. _`tes3raceBodyParts`: ../../lua/type/tes3raceBodyParts.html
.. _`niTexturingPropertyMap`: ../../lua/type/niTexturingPropertyMap.html
.. _`tes3globalVariable`: ../../lua/type/tes3globalVariable.html
.. _`tes3probe`: ../../lua/type/tes3probe.html
.. _`tes3iterator`: ../../lua/type/tes3iterator.html
.. _`tes3class`: ../../lua/type/tes3class.html
.. _`niTriShapeData`: ../../lua/type/niTriShapeData.html
.. _`niObjectNET`: ../../lua/type/niObjectNET.html
.. _`tes3armor`: ../../lua/type/tes3armor.html
.. _`niPointLight`: ../../lua/type/niPointLight.html
.. _`niLight`: ../../lua/type/niLight.html
.. _`tes3dataHandler`: ../../lua/type/tes3dataHandler.html
.. _`tes3rangeInt`: ../../lua/type/tes3rangeInt.html
.. _`tes3dialogueInfo`: ../../lua/type/tes3dialogueInfo.html
.. _`tes3weatherAsh`: ../../lua/type/tes3weatherAsh.html
.. _`niSpotLight`: ../../lua/type/niSpotLight.html
.. _`tes3dialogue`: ../../lua/type/tes3dialogue.html
.. _`tes3gameFile`: ../../lua/type/tes3gameFile.html
.. _`tes3inputController`: ../../lua/type/tes3inputController.html
.. _`tes3lockpick`: ../../lua/type/tes3lockpick.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`tes3magicEffect`: ../../lua/type/tes3magicEffect.html
.. _`string`: ../../lua/type/string.html
.. _`niTimeController`: ../../lua/type/niTimeController.html
.. _`tes3iteratorNode`: ../../lua/type/tes3iteratorNode.html
.. _`tes3fader`: ../../lua/type/tes3fader.html
.. _`tes3quest`: ../../lua/type/tes3quest.html
.. _`tes3nonDynamicData`: ../../lua/type/tes3nonDynamicData.html
.. _`tes3travelDestinationNode`: ../../lua/type/tes3travelDestinationNode.html
.. _`tes3race`: ../../lua/type/tes3race.html
.. _`tes3static`: ../../lua/type/tes3static.html
.. _`tes3clothing`: ../../lua/type/tes3clothing.html
.. _`tes3weatherBlizzard`: ../../lua/type/tes3weatherBlizzard.html
.. _`tes3weather`: ../../lua/type/tes3weather.html
.. _`tes3activator`: ../../lua/type/tes3activator.html
.. _`tes3inventory`: ../../lua/type/tes3inventory.html
.. _`tes3boundingBox`: ../../lua/type/tes3boundingBox.html
.. _`tes3birthsign`: ../../lua/type/tes3birthsign.html
.. _`tes3creatureInstance`: ../../lua/type/tes3creatureInstance.html
.. _`tes3effect`: ../../lua/type/tes3effect.html
.. _`tes3object`: ../../lua/type/tes3object.html
.. _`tes3weatherClear`: ../../lua/type/tes3weatherClear.html
.. _`number`: ../../lua/type/number.html
.. _`tes3misc`: ../../lua/type/tes3misc.html
.. _`tes3leveledListNode`: ../../lua/type/tes3leveledListNode.html
.. _`niNode`: ../../lua/type/niNode.html
.. _`function`: ../../lua/type/function.html
.. _`niVertexColorProperty`: ../../lua/type/niVertexColorProperty.html
.. _`tes3baseObject`: ../../lua/type/tes3baseObject.html
.. _`niGeometryData`: ../../lua/type/niGeometryData.html
.. _`niAmbientLight`: ../../lua/type/niAmbientLight.html
.. _`bool`: ../../lua/type/boolean.html
.. _`tes3weatherFoggy`: ../../lua/type/tes3weatherFoggy.html
.. _`mwseTimerController`: ../../lua/type/mwseTimerController.html
.. _`tes3leveledCreature`: ../../lua/type/tes3leveledCreature.html
.. _`tes3activeMagicEffect`: ../../lua/type/tes3activeMagicEffect.html
.. _`tes3cellExteriorData`: ../../lua/type/tes3cellExteriorData.html
.. _`tes3enchantment`: ../../lua/type/tes3enchantment.html
.. _`tes3container`: ../../lua/type/tes3container.html
.. _`tes3factionReaction`: ../../lua/type/tes3factionReaction.html
.. _`mwseTimer`: ../../lua/type/mwseTimer.html
.. _`tes3npc`: ../../lua/type/tes3npc.html
.. _`niTriShape`: ../../lua/type/niTriShape.html
.. _`tes3matrix33`: ../../lua/type/tes3matrix33.html
.. _`tes3actor`: ../../lua/type/tes3actor.html
.. _`tes3containerInstance`: ../../lua/type/tes3containerInstance.html
.. _`tes3magicSourceInstance`: ../../lua/type/tes3magicSourceInstance.html
.. _`niAVObject`: ../../lua/type/niAVObject.html
.. _`tes3mobileActor`: ../../lua/type/tes3mobileActor.html
.. _`tes3raceHeightWeight`: ../../lua/type/tes3raceHeightWeight.html
.. _`tes3mobileProjectile`: ../../lua/type/tes3mobileProjectile.html
.. _`tes3mobileObject`: ../../lua/type/tes3mobileObject.html
.. _`tes3door`: ../../lua/type/tes3door.html
.. _`tes3directInputMouseState`: ../../lua/type/tes3directInputMouseState.html
.. _`niPixelData`: ../../lua/type/niPixelData.html
.. _`niRTTI`: ../../lua/type/niRTTI.html
.. _`tes3alchemy`: ../../lua/type/tes3alchemy.html
.. _`tes3leveledItem`: ../../lua/type/tes3leveledItem.html
.. _`tes3reference`: ../../lua/type/tes3reference.html
.. _`niPropertyLinkedList`: ../../lua/type/niPropertyLinkedList.html
.. _`niStencilProperty`: ../../lua/type/niStencilProperty.html
.. _`tes3raceSkillBonus`: ../../lua/type/tes3raceSkillBonus.html
.. _`tes3faction`: ../../lua/type/tes3faction.html
.. _`tes3combatSession`: ../../lua/type/tes3combatSession.html
.. _`tes3weatherThunder`: ../../lua/type/tes3weatherThunder.html
.. _`tes3item`: ../../lua/type/tes3item.html
.. _`tes3weatherSnow`: ../../lua/type/tes3weatherSnow.html
.. _`tes3statistic`: ../../lua/type/tes3statistic.html
.. _`tes3ingredient`: ../../lua/type/tes3ingredient.html
.. _`tes3moon`: ../../lua/type/tes3moon.html
.. _`nil`: ../../lua/type/nil.html
.. _`niDynamicEffectLinkedList`: ../../lua/type/niDynamicEffectLinkedList.html
.. _`tes3weatherController`: ../../lua/type/tes3weatherController.html
.. _`tes3physicalObject`: ../../lua/type/tes3physicalObject.html
.. _`tes3weatherBlight`: ../../lua/type/tes3weatherBlight.html
.. _`tes3mobileNPC`: ../../lua/type/tes3mobileNPC.html
.. _`tes3regionSound`: ../../lua/type/tes3regionSound.html
.. _`tes3vector3`: ../../lua/type/tes3vector3.html
.. _`tes3wearablePart`: ../../lua/type/tes3wearablePart.html
.. _`tes3vector4`: ../../lua/type/tes3vector4.html
.. _`tes3vector2`: ../../lua/type/tes3vector2.html
.. _`tes3transform`: ../../lua/type/tes3transform.html
.. _`tes3soulGemData`: ../../lua/type/tes3soulGemData.html
.. _`tes3bodyPart`: ../../lua/type/tes3bodyPart.html
.. _`tes3region`: ../../lua/type/tes3region.html
.. _`tes3referenceList`: ../../lua/type/tes3referenceList.html
.. _`tes3lockNode`: ../../lua/type/tes3lockNode.html
.. _`tes3cell`: ../../lua/type/tes3cell.html
.. _`tes3game`: ../../lua/type/tes3game.html
.. _`niDirectionalLight`: ../../lua/type/niDirectionalLight.html
.. _`niPickRecord`: ../../lua/type/niPickRecord.html
.. _`tes3itemStack`: ../../lua/type/tes3itemStack.html
.. _`tes3raceBaseAttribute`: ../../lua/type/tes3raceBaseAttribute.html
.. _`tes3light`: ../../lua/type/tes3light.html
.. _`table`: ../../lua/type/table.html
.. _`tes3weatherCloudy`: ../../lua/type/tes3weatherCloudy.html
.. _`niTriBasedGeometry`: ../../lua/type/niTriBasedGeometry.html
.. _`niMaterialProperty`: ../../lua/type/niMaterialProperty.html
.. _`tes3apparatus`: ../../lua/type/tes3apparatus.html
.. _`tes3npcInstance`: ../../lua/type/tes3npcInstance.html
.. _`tes3actionData`: ../../lua/type/tes3actionData.html
.. _`niFormatPrefs`: ../../lua/type/niFormatPrefs.html
.. _`niColor`: ../../lua/type/niColor.html
.. _`tes3weatherRain`: ../../lua/type/tes3weatherRain.html
.. _`tes3mobilePlayer`: ../../lua/type/tes3mobilePlayer.html
.. _`tes3factionRank`: ../../lua/type/tes3factionRank.html
.. _`niSwitchNode`: ../../lua/type/niSwitchNode.html
.. _`tes3mobileCreature`: ../../lua/type/tes3mobileCreature.html
.. _`tes3packedColor`: ../../lua/type/tes3packedColor.html
.. _`tes3markData`: ../../lua/type/tes3markData.html
.. _`niPick`: ../../lua/type/niPick.html
.. _`niCollisionSwitch`: ../../lua/type/niCollisionSwitch.html
.. _`niProperty`: ../../lua/type/niProperty.html
.. _`niTriBasedGeometryData`: ../../lua/type/niTriBasedGeometryData.html
.. _`niCamera`: ../../lua/type/niCamera.html
.. _`niDynamicEffect`: ../../lua/type/niDynamicEffect.html
.. _`tes3magicEffectInstance`: ../../lua/type/tes3magicEffectInstance.html
.. _`tes3weatherOvercast`: ../../lua/type/tes3weatherOvercast.html
.. _`tes3gameSetting`: ../../lua/type/tes3gameSetting.html
.. _`tes3equipmentStack`: ../../lua/type/tes3equipmentStack.html
.. _`niSourceTexture`: ../../lua/type/niSourceTexture.html
.. _`niFogProperty`: ../../lua/type/niFogProperty.html
.. _`niGeometry`: ../../lua/type/niGeometry.html
.. _`tes3itemData`: ../../lua/type/tes3itemData.html
.. _`niTexturingProperty`: ../../lua/type/niTexturingProperty.html
