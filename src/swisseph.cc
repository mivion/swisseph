#include <node.h>
#include <v8.h>

using namespace v8;

Handle<Value> Hello (const Arguments & args) {
  HandleScope scope;
  return scope.Close (String::New ("world"));
}

void Initialize (Handle <Object> target) {
  NODE_SET_METHOD (target, "hello", Hello);
}

NODE_MODULE (swisseph, Initialize);
