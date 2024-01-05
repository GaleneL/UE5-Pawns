# PawnsExploration

Project to explore enhanced movement and mechanics with 3D Pawns and 2D Characters.
Developed with Unreal Engine 5 C++ and Blueprints.

## 3D Not Biped Pawns
This part of project was developed completely in C++. I write the code necessary to control a Pawn that is able to move, to shoot and to share the functionality with enemy pawns that the player does not control but are part of the game.

![UStaticMeshComponent RotateTurret() UCapsuleComponent ProjectileSpawnPoint float RotationRate](https://github.com/GaleneL/UE5-Pawns/assets/86707868/da25325f-423a-4b12-8d08-5458343a1df2)

The BasePawn.h can be the parent to any other type of not biped pawns with other functionality. It has just a capsule component and a base static mesh component.

The MachinePawn.h has the posibility of shoot projectiles with the Fire() method, then a turret static mesh component was added and also the projectile spawn point component from where the projectile will spawn. Also because of is though to be used with non playable turrets, a method to rotate the mesh to point to the player was written with the name RotateTurret()

MachineRobot.h is a player controllable pawn. Properties to manage enhanced input action were set (TankMappingContext, MoveAction, TurnAction, FireAction). Also a SprintArm and Camera components to watch the pawn in a comfortable position were added. Variables to set the movement speed and turn speed were added with the corresponding methods to achieve the movement.

Finally the NPC MachineTower.h Pawn can check if the player is in range to be attacked and a timer was written to shoot to the player each 2 seconds by default.

https://github.com/GaleneL/UE5-Pawns/assets/86707868/961c99ef-a09c-4ac2-b292-4262538b05fc

In Tick() function from MachineRobot.h is the code responsible to get the position of the mouse cursor and draw a blue debug sphere in the world space. That position is used to method RotateTurret() in the parent class MachinePawn.h to rotate the turret static mesh component of the robot as the above video shows.

https://github.com/GaleneL/UE5-Pawns/assets/86707868/ce3a3377-89b1-4221-87eb-f45d05b7591a

The TowerMachine.h Pawn is idle, but when the player robot get close enough to a enemy tower, the tower use the same function RotateTurret() in class MachinePawn.h to point to the player, and the method Fire() draws a red debug sphere where the projectile should be shot.

https://github.com/GaleneL/UE5-Pawns/assets/86707868/9ac26b5b-e06b-4bb5-8cbf-41a832b3d575

Finally, MachineRobot.h also is able to use the function Fire() of the parent, which also draws the same red debug spheres.

## 2D Character
