@tool
extends Node2D

enum BLOCK_TYPE {BRICK = 2, POWER = 88, EMPTY = 3}

@export var current_block: BLOCK_TYPE = BLOCK_TYPE.BRICK
@onready var state_machine: AnimationTree = $AnimationTree
@onready var sprite: Sprite2D = $BlockSprite

func _ready():
	state_machine.active = true
	sprite.frame = current_block

func _on_below_hitbox_area_entered(area):
	if area is Hitbox and area.get_parent() is Player:
		var hitbox: Hitbox = area
		
		if current_block == BLOCK_TYPE.BRICK or current_block == BLOCK_TYPE.POWER:
			state_machine.get("parameters/playback").travel("bump")
			

func _on_animation_tree_animation_finished(anim_name):
	if anim_name == "bump":
		if current_block == BLOCK_TYPE.BRICK or current_block == BLOCK_TYPE.POWER:
			current_block = BLOCK_TYPE.EMPTY
			sprite.frame = current_block
