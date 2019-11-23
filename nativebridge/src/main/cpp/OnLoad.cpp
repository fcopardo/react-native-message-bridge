//  Copyright (c) Facebook, Inc. and its affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the root directory of this source tree.

#include <fb/fbjni.h>

namespace facebook {
    namespace react {

        class DynamicHolder : public jni::HybridClass<DynamicHolder> {

        public:
            static auto constexpr kJavaDescriptor = "Lcom/sanyinchen/nativebridge/BridgeLoad;";

            static const char *getHelloDynamicStr(jni::alias_ref<jclass>) {
                std::string str = "123";
                return str.c_str();
            }

            static void registerNatives() {
                registerHybrid(
                        {
                                makeNativeMethod("getHelloDynamicStr", getHelloDynamicStr)
                        });
            }

        private:
            friend HybridBase;
            using HybridBase::HybridBase;
        };

    }
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    return facebook::jni::initialize(vm, [] {
        facebook::react::DynamicHolder::registerNatives();
    });
}