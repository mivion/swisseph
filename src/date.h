#include <node.h>
#include <v8.h>

using namespace v8;

/**
 * double swe_julday(int year, int month, int day, double hour, int gregflag)
 * =>
 * double swe_julday(int year, int month, int day, double hour, int gregflag[, function callback (result)])
 */
Handle <Value> node_swe_julday (const Arguments & args);
