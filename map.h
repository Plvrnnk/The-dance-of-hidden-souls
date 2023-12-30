#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>



const int HEIGHT_MAP = 15;
const int WIDTH_MAP = 115;
sf::String TileMap[HEIGHT_MAP] = {

"0                                                                                                                0",
"0                                                                                                                0",
"0                                                                                                                0",
"0                                                                                                                0",
"0                                                                                                                0",
"0                                                                                                                0",
"0   t                                                        t                                          t        0",
"0                                    e0                                                                          0",
"0                                         r                                r                                     0",
"0       e0         l             l0           r                        l                    e0                   0",
"0            r                r                  d                                                               0",
"0                                                    d             d                                             0",
"0                m         m                                                              m                      0",
"gggggggggggaaagggggggggggggggaaaaaaaaaaaaaaaaaaaaaaaaaaagggggggggggggggggggggggggggggggggggggggggggggggggggggggggg",
"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww",
};
#endif