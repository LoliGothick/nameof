// nameof() c++11 https://github.com/Terik23/nameof
// Vesion 0.1.3
//
// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
// Copyright (c) 2016 - 2018 Terik23 <neargye@gmail.com>.
//
// Permission is hereby  granted, free of charge, to any  person obtaining a copy
// of this software and associated  documentation files (the "Software"), to deal
// in the Software  without restriction, including without  limitation the rights
// to  use, copy,  modify, merge,  publish, distribute,  sublicense, and/or  sell
// copies  of  the Software,  and  to  permit persons  to  whom  the Software  is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
// IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
// FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
// AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
// LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once
#include <cstddef>

namespace nameof {

template <typename T>
constexpr const char* Nameof(const char* name, const size_t length) {
  return length == 0 ? name
                     : (name[length - 1] == ' ' || name[length - 1] == '.' ||
                        name[length - 1] == '>' || name[length - 1] == ':' ||
                        name[length - 1] == '&' || name[length - 1] == '*' ||
                        name[length - 1] == '+' || name[length - 1] == '~' ||
                        name[length - 1] == '-' || name[length - 1] == '!')
                           ? &name[length]
                           : Nameof<T>(name, length - 1);
}

}

#define NAMEOF_RAW_(x) #x
#define NAMEOF_RAW(x) NAMEOF_RAW_(x)

// Used to obtain the string name of a variable, function and etc.
#define NAMEOF(name) nameof::Nameof<decltype(name)>(NAMEOF_RAW(name), sizeof(NAMEOF_RAW(name)) / sizeof(char) - 1)

#define NAMEOF_FULL(name) nameof::Nameof<decltype(name)>(NAMEOF_RAW(name), 0)

#define NAMEOF_VARIABLE(variable) NAMEOF(variable)
#define NAMEOF_VAR(var) NAMEOF(var)

#define NAMEOF_VARIABLE_FULL(variable) NAMEOF_FULL(variable)
#define NAMEOF_VAR_FULL(var) NAMEOF_FULL(var)

#define NAMEOF_FUNCTION(function) NAMEOF(function)
#define NAMEOF_FUN(fun) NAMEOF(fun)

#define NAMEOF_FUNCTION_FULL(function) NAMEOF_FULL(function)
#define NAMEOF_FUN_FULL(fun) NAMEOF_FULL(fun)

// Used to obtain the string name of a type.
#define NAMEOF_TYPE(type) nameof::Nameof<type>(NAMEOF_RAW(type), sizeof(NAMEOF_RAW(type)) / sizeof(char) - 1)

#define NAMEOF_TYPE_FULL(type) nameof::Nameof<type>(NAMEOF_RAW(type), 0)
