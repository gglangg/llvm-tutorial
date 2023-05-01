/usr/lib/llvm-10/bin/opt \
-load-pass-plugin build/lib/libAddConst.so \
-passes="print<ir>" \
-disable-output examples/foo.ll 