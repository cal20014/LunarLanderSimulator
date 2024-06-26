/***********************************************************************
 * Header File:
 *    Thrust : Represents activation of thrusters
 * Author:
 *    Br. Helfrich
 * Summary:
 *    down, clockwise, and counterclockwise
 ************************************************************************/

#pragma once

#include "uiInteract.h"  // for Interface

class TestLander;
class TestThrust;

 /*****************************************************
  * THRUST
  * Represents activation of thrusters
  *****************************************************/
class Thrust
{
   friend TestLander;
   friend TestThrust;
   
public:
   // Thrust is initially turned off
   Thrust() : mainEngine(false), clockwise(false), counterClockwise(false) {}

   // Get rotation in radians per second
   double rotation() const;

   // get main engine thrust in  m / s ^ 2
   double mainEngineThrust() const
   {
      return 45000.00 / 15103.00;
   }

   // reflect what is firing
   bool isMain()    const 
   { 
      if (mainEngine == true)
         return true;
      
      return false;
   }
   bool isClock()   const 
   { 
      if (clockwise == true)
         return true;

      return false;        
   }
   bool isCounter() const 
   { 
      if (counterClockwise == true)
         return true;

      return false; 
   }

   // set the thrusters
   void set(const Interface* pUI);

private:
   bool mainEngine;
   bool clockwise;
   bool counterClockwise;
};
