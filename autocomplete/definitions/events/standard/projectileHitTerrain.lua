return {
	description = "The projectileHitTerrain event fires when a projectile collides with terrain.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileProjectile",
			readonly = true,
			description = "The mobile projectile that is expiring.",
		},
		["collisionPoint"] = {
			type = "tes3vector3",
			readonly = true,
			description = "The collision point of the mobile projectile.",
		},
		["position"] = {
			type = "tes3vector3",
			readonly = true,
			description = "The position of the mobile projectile.",
		},
		["velocity"] = {
			type = "tes3vector3",
			readonly = true,
			description = "The velocity of the mobile projectile.",
		},
		["firingReference"] = {
			type = "tes3reference",
			readonly = true,
			description = "Reference to the actor that fired the projectile.",
		},
		["firingWeapon"] = {
			type = "tes3weapon",
			readonly = true,
			description = "The weapon that fired the projectile.",
		},
	},
}