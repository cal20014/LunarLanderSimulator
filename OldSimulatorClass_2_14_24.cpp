///**********************************************************************
// * LAB 06
// * Authors:
// *   Br. Helfrich, Isaac Huffman, Grant Call
// * Summary:
// *   Lunar Lander simulation. This is the Game class and main()
// **********************************************************************/
//
//#include "position.h"    // everything should have a point
//#include "angle.h"       // angle of the lander
//#include "uiInteract.h"  // for INTERFACE
//#include "uiDraw.h"      // for RANDOM and DRAW*
//#include "ground.h"      // for GROUND
//#include "test.h"        // for the unit tests
//#include "lander.h"      // for the lander
//#include "star.h"        // for the stars
//#include <cmath>         // for SQRT
//#include <cassert>       // for ASSERT
//#include <iostream>
//using namespace std;
//
//const double GRAVITY_CONSTANT = -1.625;
//
///*************************************************************************
// * SIMULATOR
// * Everything pertaining to the simulator.
// *************************************************************************/
//class Simulator
//{
//public:
//   // set up the simulator
//   Simulator(const Position& posUpperRight) :\
//      phase(0), ground(posUpperRight)
//   {
//      lander = new Lander(posUpperRight);
//      lander->reset(posUpperRight);
//
//      // Initialize the stars
//      for (int i = 0; i < 50; i++)
//      {
//         stars[i].reset(posUpperRight.getX(), posUpperRight.getY());
//      }
//   }
//
//   // display stuff on the screen
//   void display(Thrust thrust);
//   bool gamePlay();
//
//   unsigned char phase;
//   Ground ground;
//   Lander* lander;
//   Star stars[50];
//};
//
///**********************************************************
// * DISPLAY
// * Draw on the screen
// **********************************************************/
//void Simulator::display(Thrust thrust)
//{
//   ogstream gout;
//
//   if (gamePlay())
//   {
//      lander->coast(lander->input(thrust, GRAVITY_CONSTANT), 0.06);
//   }
//   lander->draw(thrust, gout);
//
//   // draw the stars
//   for (int i = 0; i < 50; i++)
//   {
//      stars[i].draw(gout);
//   }
//
//   // draw the ground
//   ground.draw(gout);
//}
//
//
//bool Simulator::gamePlay() {
//   cout << lander->getSpeed() << endl;
//   if (ground.hitGround(lander->getPosition(), lander->getWidth()))
//   {
//      lander->crash();
//      cout << "crash on ground" << endl;
//      return false;
//   }
//   if (ground.onPlatform(lander->getPosition(), lander->getWidth()) && lander->getSpeed() <= lander->getMaxSpeed())
//   {
//      lander->land();
//      cout << "land" << endl;
//      return false;
//   }
//   if (ground.onPlatform(lander->getPosition(), lander->getWidth()) && lander->getSpeed() > lander->getMaxSpeed())
//   {
//      lander->crash();
//      cout << "crash on platform, too fast";
//      return false;
//   }
//
//   return true;
//
//}
//
///*************************************
// * CALLBACK
// * Handle one frame of the simulator
// **************************************/
//void callBack(const Interface* pUI, void* p)
//{
//   // the first step is to cast the void pointer into a game object. This
//   // is the first step of every single callback function in OpenGL. 
//   Simulator* pSimulator = (Simulator*)p;
//   // draw the game
//
//   Thrust thrust;
//   thrust.set(pUI);
//   pSimulator->display(thrust);
//
//
//
//
//
//   // handle input
//   // if (pUI->isRight())
//   //    pSimulator->a.add(-0.1);
//   // if (pUI->isLeft())
//   //    pSimulator->a.add( 0.1);
//
//}
//
///*********************************
// * Main is pretty sparse.  Just initialize
// * my LM type and call the display engine.
// * That is all!
// *********************************/
//#ifdef _WIN32
//#include <windows.h>
//int WINAPI WinMain(
//   _In_ HINSTANCE hInstance,
//   _In_opt_ HINSTANCE hPrevInstance,
//   _In_ LPSTR pCmdLine,
//   _In_ int nCmdShow)
//#else // !_WIN32
//int main(int argc, char** argv)
//#endif // !_WIN32
//{
//   // Run the unit tests
//#ifdef _WIN32
//   AllocConsole();
//   FILE* stream;
//   errno_t err;
//   err = freopen_s(&stream, "CONOUT$", "a", stdout);
//#endif // _WIN32
//   testRunner();
//
//   // Initialize OpenGL
//   Position posUpperRight(400, 400);
//   Interface ui("Lunar Lander", posUpperRight);
//
//   // Initialize the game class
//   Simulator simulator(posUpperRight);
//
//   ogstream myStream;
//
//
//   // set everything into action
//   ui.run(callBack, (void*)&simulator);
//
//   return 0;
//}