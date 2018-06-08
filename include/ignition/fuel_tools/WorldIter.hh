/*
 * Copyright (C) 2018 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef IGNITION_FUEL_TOOLS_WORLDITER_HH_
#define IGNITION_FUEL_TOOLS_WORLDITER_HH_

#include <memory>

#include "ignition/fuel_tools/Helpers.hh"
#include "ignition/fuel_tools/World.hh"

namespace ignition
{
  namespace fuel_tools
  {
    /// \brief forward declaration
    class WorldIterPrivate;
    class WorldIterFactory;

    /// \brief class for iterating through worlds
    class IGNITION_FUEL_TOOLS_VISIBLE WorldIter
    {
      friend WorldIterFactory;

      /// \brief Construct an iterator with the data it needs to function
      protected: explicit WorldIter(std::unique_ptr<WorldIterPrivate> _dptr);

      /// \brief Move constructor
      public: WorldIter(WorldIter &&_old);

      /// \brief Default destructor.
      public: ~WorldIter();

      /// \return False once the iterator is one past the end of the worlds
      public: operator bool() const;

      /// \brief Prefix increment
      public: WorldIter &operator++();

      /// \brief Dereference operator
      public: World &operator*();

      /// \brief -> operator
      public: World *operator->();

      /// \brief Private data pointer.
      private: std::unique_ptr<WorldIterPrivate> dataPtr;
    };
  }
}

#endif
