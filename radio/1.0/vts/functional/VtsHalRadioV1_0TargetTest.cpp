/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gtest/gtest.h>
#include <hidl/GtestPrinter.h>
#include <hidl/ServiceManagement.h>
#include <radio_hidl_hal_utils_v1_0.h>

GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(RadioHidlTest);
INSTANTIATE_TEST_SUITE_P(PerInstance, RadioHidlTest,
                         testing::ValuesIn(android::hardware::getAllHalInstanceNames(
                                 ::android::hardware::radio::V1_0::IRadio::descriptor)),
                         android::hardware::PrintInstanceNameToString);

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // setup seed for rand function
    int seedSrand = time(NULL);
    std::cout << "seed setup for random function (radio):" + std::to_string(seedSrand) << std::endl;
    srand(seedSrand);

    int status = RUN_ALL_TESTS();
    LOG(INFO) << "Test result = " << status;

    return status;
}
