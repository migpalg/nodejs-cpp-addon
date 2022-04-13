#include <napi.h>
#include "Samples/FunctionExample.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
  return FunctionExample::Init(env, exports);
}

NODE_API_MODULE(hello, InitAll)