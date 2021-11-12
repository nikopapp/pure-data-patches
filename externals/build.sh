gcc src/helloworld.c -I ../../../Projects/Open-Source/pure-data/src/ -o helloworld.pd_darwin -undefined suppress -flat_namespace -bundle
gcc src/mycounter.c -I ../../../Projects/Open-Source/pure-data/src/ -o mycounter.pd_darwin -undefined suppress -flat_namespace -bundle
gcc src/xfade~.c -I ../../../Projects/Open-Source/pure-data/src/ -o xfade~.pd_darwin -undefined suppress -flat_namespace -bundle
gcc src/midilabel.c -I ../../../Projects/Open-Source/pure-data/src/ -o midilabel.pd_darwin -undefined suppress -flat_namespace -bundle
gcc src/midi2freq.c -I ../../../Projects/Open-Source/pure-data/src/ -o midi2freq.pd_darwin -undefined suppress -flat_namespace -bundle
g++ src/hiworld.cpp -o hiworld.pd_darwin -I ../../../Projects/Open-Source/pure-data/src/ -undefined suppress -flat_namespace -bundle
g++ src/plus.cpp -o plus.pd_darwin -I ../../../Projects/Open-Source/pure-data/src/ -undefined suppress -flat_namespace -bundle

