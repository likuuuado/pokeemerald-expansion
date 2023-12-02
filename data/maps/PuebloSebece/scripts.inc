PuebloSebece_MapScripts::
	.byte 0

@scripts del mapa

PuebloSebece_EventScript_ElRaro::
	faceplayer
	lock
	msgbox PuebloSebece_Text_ElRaro, MSGBOX_NPC
	waitmessage
	release 
	applymovement 4, PuebloSebece_Movement_ElRaro
	waitmovement 4,
	removeobject 4,
	setflag FLAG_EL_RARO_1
	end

PuebloSebece_EventScript_Zigzagoon::
	faceplayer
	lock
	showmonpic SPECIES_ZIGZAGOON, 20, 4 
	msgbox PuebloSebece_Text_Zigzagoon, MSGBOX_NPC
	hidemonpic
	release
	end

PuebloSebece_EventScript_Don_Roberto::
	faceplayer
	lock
	msgbox PuebloSebece_Text_Don_Roberto, MSGBOX_NPC
	release
	end

PuebloSebece_EventScript_Nena::
	faceplayer
	lock
	msgbox PuebloSebece_Text_Nena, MSGBOX_NPC
	release
	end

PuebloSebece_EventScript_Casa_De_Gema::
	msgbox PuebloSebece_Text_Casa_De_Gema, MSGBOX_SIGN
	waitbuttonpress 
	closemessage
	end

PuebloSebece_EventScript_Evan_No_Esta::
	msgbox PuebloSebece_Text_Evan_No_Esta, MSGBOX_SIGN
	waitbuttonpress
	closemessage
	end

@Textos de personajes

PuebloSebece_Text_Don_Roberto::
	.string "Don Roberto: Es una lastima parecian\n"
	.string "una familia muy linda\p"
	.string "ahora hasta su cas perdio la belleza.$"

PuebloSebece_Text_ElRaro::
	.string "QUE MIRAS, DEJAME SOLO.$"


PuebloSebece_Text_Zigzagoon::
	.string "Zigzaaaaaa.$"

PuebloSebece_Text_Nena::
	.string "Lo bueno de esas tormentas raras\n"
	.string "es que dejan muchos charcos.$"

@textos al interactuar

PuebloSebece_Text_Casa_De_Gema::
	.string "La casa de gema sigue abandonada\n"
	.string "capaz algun dia alguien la compre.$"

PuebloSebece_Text_Evan_No_Esta:: 
	.string "No atiende, parece que no esta\n"
	.string "en su casa ahora mismo.$"

@movimientos de personajes

PuebloSebece_Movement_ElRaro::
	face_right
	jump_2_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	set_invisible
	step_end


