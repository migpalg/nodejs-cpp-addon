#include <napi.h>
#include <iostream>

#ifndef FUNCTION_EXAMPLE_H
#define FUNCTION_EXAMPLE_H

namespace FunctionExample
{
  std::string Hello();
  int Fibo(int n);
  Napi::Number FiboWrapped(const Napi::CallbackInfo &info);
  Napi::String HelloWrapped(const Napi::CallbackInfo &info);
  Napi::Object Init(Napi::Env env, Napi::Object exports);
}

#endif