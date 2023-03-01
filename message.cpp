#include <stdio.h>

#define UDEF_DEBUG_IMPLEMENTATION
#undef UDEF_FPRINTF
#define UDEF_FPRINTF(file, format, ...) fprintf(file, format, __FILE__, __LINE__, __VA_ARGS__)
#include "udef_print.h"

// struct Json;

// enum NODE_TYPE {
//   NODE_INT,
//   NODE_FLOAT,
//   NODE_NULL,
//   NODE_CONST_STRING,
//   NODE_STRING,
//   NODE_JSON,
//   NODE_ARRAY,

//   NODE_COUNT,
// };

// #ifndef ARRAY_CAPACITY
// #define ARRAY_CAPACITY 64
// #endif

// struct Node;

// union NODE_VAL {
//   int v_int;
//   float v_float;
//   char* v_string;
//   const char* v_const_string;
//   Json* v_json;
//   Node* v_array[ARRAY_CAPACITY];
// };

// struct Node {
//   NODE_TYPE type;
//   NODE_VAL val;

//   ~Node() {
//     if (type == NODE_STRING) {
//       printf("delete NODE_STRING\n");
//       delete val.v_string;
//     }
//     if (type == NODE_STRING || type == NODE_CONST_STRING) {
//       val.v_string = nullptr;
//     }
//     if (type == NODE_JSON) {
//       printf("delete NODE_JSON\n");
//       delete val.v_json;
//       val.v_json = nullptr;
//     }
//     if (type == NODE_ARRAY) {
//       printf("delete NODE_ARRAY\n");
//       for (Node* json: val.v_array) {
//         delete json;
//         json = nullptr;
//       }
//     }
//   }
// };

// struct Record {
//   const char* key;
//   Node* val;

//   ~Record() {
//     if (key) {
//       printf("delete Record key: \"%s\"\n", key);
//     }
//     delete val;
//     val = nullptr;
//   }
// };

// #ifndef RECORD_CAPACITY
// #define RECORD_CAPACITY 64
// #endif

// struct Json {
//   Record* records[RECORD_CAPACITY];

//   ~Json() {
//     fprintf(stderr, "delete json\n");
//     for (Record* record: records) {
//       delete record;
//     }
//   }
// };

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

int main() {
  udef_print printer(__FILE__);

  int a = 19, b = 19;
  if (a == b)
    printer.observe(__LINE__)->success("%d == %d is always true.\n", a, b);

  b = 7;
  if (a != b)
    printer.observe(__LINE__)->error("%d is not equal to %d.\n", a, b);

  char* p = nullptr;
  if (!p)
    printer.observe(__LINE__)->warning("%s is nullptr at %p.\n", "\"p\"", p);

  printer.observe(__LINE__)->info("This is the end of the program. %c%c%c%c\n", 'B', 'y', 'e', '!');

  return 0;
}








// Json json = { .records = {
//   new Record({
//     .key = "null",
//     .val = new Node({ .type = NODE_NULL })
//   }),
//   new Record({
//     .key = "int",
//     .val = new Node({ .type = NODE_INT, .val = { .v_int = 1 } })
//   }),
//   new Record({
//     .key = "nested float",
//     .val = new Node({ .type = NODE_JSON, .val = { .v_json = new Json({ .records = {
//       new Record({
//         .key = "float",
//         .val = new Node({ .type = NODE_FLOAT, .val = { .v_float = 1.2 } })
//       })
//     }})}})
//   }),
//   new Record({
//     .key = "nested string",
//     .val = new Node({ .type = NODE_JSON, .val = { .v_json = new Json({ .records = {
//       new Record({
//         .key = "string",
//         .val = new Node({ .type = NODE_CONST_STRING, .val = { .v_const_string = "Hello world" } })
//       })
//     }})}})
//   }),
//   new Record({
//     .key = "array",
//     .val = new Node({ .type = NODE_ARRAY, .val = { .v_array = {
//       new Node({
//         .type = NODE_JSON,
//         .val = { .v_json = new Json({ .records = {
//           new Record({
//             .key = "array[0].null",
//             .val = new Node({ .type = NODE_NULL })
//           })}})
//         }})
//     }}})
//   })
// }};
// assert(1 == 2, "%s:%d: error:", __FILE__, __LINE__);
// fprintf(stderr, BOLDWHITE "%s:%d: " BOLDRED "error: \n", __FILE__, __LINE__);
