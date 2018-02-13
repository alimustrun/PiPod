//
// Created by fritsch on 13/02/18.
//

#include <gtest/gtest.h>
#include "Number.h"

const bool Number::isOdd(int nb)
{
    return (nb % 2) != 0;
}

TEST(NumberTest, Odd) {
    Number *number = new Number();
EXPECT_EQ(true, number->isOdd(1));
}