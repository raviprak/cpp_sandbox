#include <gtest/gtest.h>
#include <string>
#include <string_view>

#include "grpc_example_server.h"
#include "grpc_example_client_lib.h"

constexpr int64_t kPORT = 12345;

class GrpcExampleServerTest : public ::testing::Test
{
public:
    void SetUp() override
    {
        service_.StartDoublingRandomWaitService(kPORT);
        client_ = std::make_unique<DoublingClient>(absl::StrCat("localhost:", kPORT));
    }

    std::unique_ptr<DoublingClient> client_;

private:
    DoublingRandomWaitServiceImpl service_;
};

TEST_F(GrpcExampleServerTest, FiveDoubled)
{
    absl::StatusOr<int64_t> reply_or = client_->SendRequest(5);
    ASSERT_EQ(reply_or.status(), absl::OkStatus());
    EXPECT_EQ(reply_or.value(), 10);
}