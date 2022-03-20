# cub3d
A graphic project aimed at introducing raycasting technology
***
Compilation commands:

`make` - compilation

`make re` - recompilation (deleting everything and compiling again)

`make clean` - deleting object files (.o)

`make fclean` - deleting object files (.o) and executable file
***
Program launch: `./cub3D *map*`
***
| Map example | Description |
| ---- | ---- |
| ![](https://i.ibb.co/w6sTX7L/map3.png) | `NO` - north texture <br/> `EA` - east texture <br/> `WE` - west texture <br/> `SO` - south texture <br/> <br/> `F` - floor color in rgb format <br/> `C` - celling color in rgb format <br/> <br/> `1` is a wall <br/> `0` is empty <br/> <br/> `W` is the player's position indicating the <br/>  direction they are facing when they spawn <br/> May be: `N`,`S`,`E`,`W`|

The *maps* folder contains maps for checking the program's performance with invalid map names/extensions: `.cub`, `error_map.cur`

Exactly the same verification files are available in the *textures* folder, they check, respectively, the validity of texture names and extensions: `.xpm`, `text_error.xpe`
***
Screenshots of the program's performance:

<img src="https://i.ibb.co/vcwBDWV/anime.png" alt="anime" border="0">

<img src="https://i.ibb.co/ns3PrY9/rus.png" alt="rus" border="0">
