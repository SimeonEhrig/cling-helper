// # Copyright (C) Simeon Ehrig
//
// cling-helper is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// ######################################################################
// # The script gives you the start arguments of cling
// ######################################################################

#include "cling/Interpreter/IncrementalCUDADeviceCompiler.h"
#include "cling/Interpreter/Interpreter.h"
#include "cling/Interpreter/InvocationOptions.h"
#include "llvm/Support/raw_ostream.h"
#include <vector>

std::vector<const char *> get_args() {
  return gCling->getOptions().CompilerOpts.Remaining;
}

// returns a empty list, if the CUDA mode is disabled
std::vector<const char *> get_ptx_args() {
  if (gCling->getCUDACompiler() == nullptr) {
    return std::vector<const char *>();
  }

  return gCling->getCUDACompiler()
      ->getPTXInterpreter()
      ->getOptions()
      .CompilerOpts.Remaining;
}
