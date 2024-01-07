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

This part of the project is the development of a 2D Character and 2D enemies in 3D environments with blueprints and PaperZD plugin.

https://github.com/GaleneL/UE5-Pawns/assets/86707868/4a3ade91-af6c-4870-9166-d695ff1daf2c

Animations were set by state machine inside an animation blueprint of the PaperZD plugin, and are allocated in an animation source object.

![image](https://github.com/GaleneL/UE5-Pawns/assets/86707868/d9f35ef4-b0d4-4939-ad3a-ecd8292b9c41)

https://github.com/GaleneL/UE5-Pawns/assets/86707868/6f5f0484-5609-4749-905c-1ea898fd8fd5

The BP_Base2DChar has a box collision component with the name Hitbox, this is activated with a notify state blueprint in certain frames of the attack animation of the characters, when this hitbox is activated and the character that receives the attack has an overlap event from this hitbox the stunned animation is played.
![image](https://github.com/GaleneL/UE5-Pawns/assets/86707868/894f8202-35e9-41c4-b98a-3e66c0969c5f)

https://github.com/GaleneL/UE5-Pawns/assets/86707868/ab12df27-99b9-4e99-b2ce-1ed89206c9f0






