# Life symulation

## Run

Use PO1.sin with Visual Studio. **Program created on windows, 
due to some console commands may not work on other systems.**

## Descriptoion

This repository contains a program that simulates lives of animals and plants. All of these have self statistics.
Player can move on board using arrows. If collision occurs, compare the object statistics, and one of these is removed.

## Rules

1. The game is played in turns.
1. The order of moves depends on the initiative.
1. Organisms are aging.
1. Contact of the same species (if mature) leads to a new animal.
1. The collision of different species leads to the death of one of them. The one with the greater strength or the one that defends itself survives.

## Statistics

| Name                | Symbol | Strength | Initiative | Special     |
| ------------------- | ------ | -------- | ---------- | ----------- |
| Zolw                | Z      | 2        | 1          | Have a lower strength to attack than to defend. |
| Wilk                | W      | 9        | 5          | ----------- |
| Owca                | O      | 4        | 4          | ----------- |
| Lis                 | L      | 3        | 7          | Avoids stronger creatures. |
| Antylopa            | Z      | 2        | 1          | Moves on two fields, have a half chance to dodge attack. |
| BarszczSosnowskiego | s      | 10       | 0          | Attacks neighboring animals. |
| Guarana             | g      | 0        | 0          | Add 3 strength. |
| Mlecz               | m      | 0        | 0          | Three times the reproduction. |
| Trawa               | t      | 0        | 0          | ----------- |
| WilczaJagoda        | j      | 99       | 0          | Kills organism that ate it. |
| Czlowiek            | @      | 5        | 4          | Player controls it. Has a special ability. |

## Player

- Arrows: movment
- Esc: stop game
- Key Q: use skill
- Key U: save game
- Key T: load game

The game is saved in the data.dat file.

Special skill removes neighboring organisms.