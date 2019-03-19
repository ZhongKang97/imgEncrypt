
# # add_executable(AR_RunVersion_ZK 181224_lineAndBlobDetect_TwoThread.cpp)
# target_link_libraries(AR_RunVersion_ZK ZK_Version ${THIRD_PARTY_LIBS})
add_library(coder SHARED 190316_imgEncrypt.cpp)
add_executable(demo demoApp.cpp)
target_link_libraries(demo coder
${THIRD_PARTY_LIBS})
