Ruta21_MapScripts::
	.byte 0

.set LOCALID_EVAN, 3

@ scripts del mapa

Ruta_21_EventScript_Eleccion_De_Starter::
	setobjectxy LOCALID_EVAN, 9, 19
	applymovement OBJ_EVENT_ID_PLAYER, Ruta_21_Movement_Prota_Llega
	waitmovement 0,
	msgbox Ruta_21_Text_Llegaste, MSGBOX_NPC
	waitmessage
	applymovement 4, Ruta_21_Movement_Mochila_Aparece
	waitmovement 4
	setobjectxy 4, 10, 23
	applymovement 3, Ruta_21_Movement_Evan_Salta
	waitmovement 3, 
	msgbox Ruta_21_Text_Elegi_Uno, MSGBOX_NPC
	waitmessage
	addvar VAR_ESTADO_RUTA_21, 1
	end

Ruta_21_EventScript_Eleccion_De_Starter_2::
	setflag FLAG_SYS_POKEMON_GET
	special ChooseStarter
	msgbox Ruta_21_Text_Se_Ven_Bien, MSGBOX_NPC
	waitmessage
	applymovement 4, Ruta_21_Movement_Mochila_Desaparece 
	removeobject 4,
	additem ITEM_POKE_BALL, 5
	msgbox Ruta_21_Text_Te_Espero_Al_final, MSGBOX_NPC
	waitmessage
	applymovement LOCALID_EVAN, Ruta_21_Movement_Evan_Se_Va
	waitmovement 3,
	removeobject LOCALID_EVAN
	setflag FLAG_MOCHILA_DE_STARTERS
	setrespawn HEAL_LOCATION_PUEBLO_SEBECE
	addvar VAR_ESTADO_RUTA_21, 1 
	end

Ruta_21_EventScript_Escape_Por_El_Sur::
	msgbox Ruta_21_Text_No_Te_Vayas, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, Ruta_21_Movement_Escape_Por_El_Sur
	waitmovement 0,
	end

Ruta_21_EventScript_Escape_Por_El_Norte::
	msgbox Ruta_21_Text_No_Te_Vayas, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, Ruta_21_Movement_Escape_Por_El_Norte
	waitmovement 0,
	end

Ruta_21_EventScript_Escape_Por_El_Este::
	msgbox Ruta_21_Text_Falta_Pelear, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, Ruta_21_Movement_Escape_Por_El_Este
	waitmovement 0,
	end

Ruta_21_EventScript_Entrenadores_Derrotados::
	setweather WEATHER_RAIN
	doweather 
	applymovement 5, Ruta_21_Movement_Fin_De_Ruta
	waitmovement 5,
	msgbox Ruta_21_Text_Empezo_La_Lluvia, MSGBOX_NPC
	waitmessage
	applymovement 5, Ruta_21_Movement_Lluvia
	applymovement OBJ_EVENT_ID_PLAYER, Ruta_21_Movement_Lluvia
	addvar VAR_ESTADO_RUTA_21, 1
	fadescreen 1
	msgbox Ruta_21_Text_Cuando_Amanezca, MSGBOX_NPC
	waitmessage
	resetweather
	warpsilent MAP_COSTA_DITOPLAYA, -1, 9, 8 
	fadescreen 0
	end

Ruta_21_EventScript_Trainer_Tobias::
	trainerbattle_single TRAINER_TOBIAS, Ruta_21_Text_TobiasIntro, Ruta_21_Text_TobiasDefeated
	addvar VAR_ESTADO_RUTA_21, 1
	msgbox Ruta_21_Text_Tobias_PostBattle, MSGBOX_AUTOCLOSE
	waitmessage
	end


Ruta_21_EventScript_Trainer_Santiago::
	trainerbattle_single TRAINER_SANTI, Ruta_21_Text_SaniagoIntro, Ruta_21_Text_SantiagoDefeated
	addvar VAR_ESTADO_RUTA_21, 1
	msgbox Ruta_21_Text_Santiago_PostBattle, MSGBOX_AUTOCLOSE
	waitmessage
	end

Ruta_21_EventScript_Trainer_Derrotado::
	addvar VAR_ESTADO_RUTA_21, 1 
	end

@ textos de personajes

Ruta_21_Text_Llegaste::
	.string "Evan: Holaaaa, llegaste por fin\n"
	.string "esperame ahi, atrapa esto.$"

Ruta_21_Text_Elegi_Uno::
	.string "Evan: Cuanto tiempo sin vernos\n"
	.string "seguro me extrañaste mucho\p"
	.string "Tu: Si seguro...\p"
	.string "Evan: Bueno no demos mucha vuelta\n"
	.string "tengo 3 iniciales, elegi uno.$"

Ruta_21_Text_Se_Ven_Bien::
	.string "Evan: Se ven bien juntos, tu papa\n"
	.string "seguro estaria orgulloso de vos\p"
	.string "Tu: Mejor no hablemos de el\p"
	.string "Evan: Entiendo, te gustaria hacer este\n"
	.string "viaje con el y no conmigo.$"
	
Ruta_21_Text_Te_Espero_Al_final::
	.string "Mejor te espero al final de la ruta\n"
	.string "hay entrenadores en el camino con los que\p"
	.string "podes combatir antes de irnos.$"

Ruta_21_Text_Empezo_La_Lluvia::
	.string "Evan: Vamos rapido al centro pokemon\n" 
	.string "antes que nos enfermemos\p"
	.string "ahi vamos a poder hablar tranquilos.$"

Ruta_21_Text_Cuando_Amanezca::
	.string "Evan: Cuando amnezca vamos a ir hasta\n"
	.string "ciudad Niamatina, las cosas ahi no \p"
	.string "estan del todo bien, quiero que veas\n"
	.string "la razon de este viaje\p"
	.string "ademas ahi esta el primer torneo de\n"
	.string "la liga, espero que sigas queriendo\p"
	.string "ser quien la gane.$"

Ruta_21_Text_Santiago_PostBattle::
	.string "La proxima vez que nos veamos\n"
	.string "voy a ganar yo.$"

Ruta_21_Text_Tobias_PostBattle::
	.string "Tampoco te creas tan fuerte.$"

@ textos al interactuar

Ruta_21_Text_TobiasIntro::
	.string "preparate para perder.$"

Ruta_21_Text_TobiasDefeated::
	.string "Bueno... tuviste suerte.$"

Ruta_21_Text_SaniagoIntro::
	.string "Bichos ataquen.$"

Ruta_21_Text_SantiagoDefeated::
	.string "mis pobres bichos.$"

Ruta_21_Text_Falta_Pelear::
	.string "Antes tengo que vencerlos a los dos.$"

Ruta_21_Text_No_Te_Vayas::
	.string "Evan: No te vayas todavia\n"
	.string "antes elegi un inicial"

@ movimientos de personajes

Ruta_21_Movement_Escape_Por_El_Norte::
	walk_down
	step_end

Ruta_21_Movement_Escape_Por_El_Sur::
	walk_up
	step_end

Ruta_21_Movement_Escape_Por_El_Este::
	walk_left
	step_end

Ruta_21_Movement_Mochila_Aparece::
	set_invisible
	walk_down
	walk_down
	walk_down
	set_visible
	step_end

Ruta_21_Movement_Prota_Llega::
	walk_up
	walk_up
	walk_right
	walk_up
	face_up
	lock_facing_direction
	step_end

Ruta_21_Movement_Evan_Salta::
	walk_down
	jump_down
	walk_down
	step_end

Ruta_21_Movement_Mochila_Desaparece::
	set_invisible
	step_end

Ruta_21_Movement_Evan_Se_Va::
	walk_right
	walk_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	set_invisible
	step_end

Ruta_21_Movement_Lluvia::	
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Ruta_21_Movement_Fin_De_Ruta::
	walk_down
	face_left
	set_visible
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end


