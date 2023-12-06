FIXES
* le joueur ne commence pas dans la direction indiquée dans la map (toujours vers l'est, dir = 0) à cause de rotate_player qui utilise ce ptn de mlx_get_mouse_pos je pense (besoin d'initialiser les variables x et y pointées ?)
* retourner les textures telle des chausettes (les sud et l'ouest)
* refresh la vue lors du pressage du boutton d'ouverture de la porte.

DISCUSS
* Pb : les collisions et le raycasting sont basés sur une map contenant uniquement des '0' et des '1'. Avec des portes (par exemple) il y a aussi des 'C' et 'O' à considérer comme murs ou tiles "walkables". Donc soit on travaille vraiment avec MAP_SYMBOLS et MAP_WALKABLE_SYMBOL (ce qui alourdit le traitement) soit on travaille avec deux matrices pour la map : l'originale et une copie remplie / traduite avec seulement des '0' et des '1' (la conversion se faisant seulement quand on ouvre / ferme une porte pour l'instant). Cette deuxièeme solution oblige à revoir le code un peu de partout pour savoir avec quelle matrice on veut bosser à ce moment là. Autre idée ?

FEATURES
* animation ? Sprites
* faire une fenetre d'aide avec les controles ?

* resume des features :

~ Help ~

	left click : inspect front near element
	right click : toggle mouse control
	middle click : toggle binoculars
	mouse scroll : change FOV
	backspace : reset FOV
	left shift : cycle through walk / run / sprint
	asde : move forward / backwards / strafe
	left / right : rotate
	space : interact w/ door
	esc : quit
	tab : toggle minimap
