#include "FunctionExample.h"

int FunctionExample::Fibo(int n)
{
  if (n <= 1)
  {
    return n;
  }

  return FunctionExample::Fibo(n - 1) + FunctionExample::Fibo(n - 2);
}

std::string FunctionExample::Hello()
{
  return "Hello world!";
}

Napi::String FunctionExample::HelloWrapped(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  Napi::String returnValue = Napi::String::New(env, FunctionExample::Hello());
  return returnValue;
}

Napi::Number FunctionExample::FiboWrapped(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  if (info.Length() != 1 || !info[0].IsNumber())
  {
    Napi::TypeError::New(env, "Number Expected").ThrowAsJavaScriptException();
  }

  Napi::Number n = info[0].As<Napi::Number>();

  Napi::Number returnValue = Napi::Number::New(env, FunctionExample::Fibo(n.Int32Value()));

  return returnValue;
}

Napi::Object FunctionExample::Init(Napi::Env env, Napi::Object exports)
{
  exports.Set("hello", Napi::Function::New(env, FunctionExample::HelloWrapped));
  exports.Set("fibo", Napi::Function::New(env, FunctionExample::FiboWrapped));

  return exports;
}