#include "pch.h"
#include "gtest\gtest.h"
#include "../lab2/Nephroid.h"
#include "../lab2/Nephroid.cpp"

TEST(NephroidConstructor, DefaultConstructor)
{
	Prog2::NEPHROID a1;
	ASSERT_EQ(1, a1.getR());
}
TEST(NephroidConstructor, InitConstructors)
{
	Prog2::NEPHROID a2(3);
	ASSERT_EQ(3, a2.getR());
}
TEST(NephroidConstructor, TestException)
{
	ASSERT_ANY_THROW(Prog2::NEPHROID(-5));
}
TEST(NephroidMethods, Setters)
{
	Prog2::NEPHROID a;
	a.setR(2);
	ASSERT_EQ(2, a.getR());
	ASSERT_ANY_THROW(a.setR(-1));
}
TEST(NephroidMethods, Parameters)
{
	const double PI = 3.14159265, err = 0.00001;
	Prog2::NEPHROID a1;
	ASSERT_NEAR(12 * PI, a1.area(), err);
	ASSERT_NEAR(24, a1.perimeter(), err);
	ASSERT_NEAR(0, a1.curvature(0), err);
	ASSERT_NEAR(2, a1.f(0).x, err);
	ASSERT_NEAR(0, a1.f(0).y, err);
	ASSERT_NEAR(3, a1.curvature(PI / 2), err);
	ASSERT_NEAR(0, a1.f(PI / 2).x, err);
	ASSERT_NEAR(4, a1.f(PI / 2).y, err);
	ASSERT_STREQ("(x ^ 2 + y ^ 2 - 4.00) ^ 3 = 108.00 * x^2", a1.frm());
	Prog2::NEPHROID a2(2);
	ASSERT_NEAR(PI * 48, a2.area(), err);
	ASSERT_NEAR(48, a2.perimeter(), err);
	ASSERT_NEAR(0, a2.curvature(0), err);
	ASSERT_NEAR(4, a2.f(0).x, err);
	ASSERT_NEAR(0, a2.f(0).y, err);
	ASSERT_NEAR(6, a2.curvature(PI / 2), err);
	ASSERT_NEAR(0, a2.f(PI / 2).x, err);
	ASSERT_NEAR(8, a2.f(PI / 2).y, err);
	ASSERT_STREQ("(x ^ 2 + y ^ 2 - 16.00) ^ 3 = 1728.00 * x^2", a2.frm());
	Prog2::NEPHROID a3(0);
	ASSERT_NEAR(0, a3.area(), err);
	ASSERT_NEAR(0, a3.perimeter(), err);
	ASSERT_NEAR(0, a3.curvature(0), err);
	ASSERT_NEAR(0, a3.f(0).x, err);
	ASSERT_NEAR(0, a3.f(0).y, err);
	ASSERT_NEAR(0, a3.curvature(PI / 2), err);
	ASSERT_NEAR(0, a3.f(PI / 2).x, err);
	ASSERT_NEAR(0, a3.f(PI / 2).y, err);
	ASSERT_STREQ("x ^ 2 + y ^ 2 = 0", a3.frm());
}
int _tmain(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}