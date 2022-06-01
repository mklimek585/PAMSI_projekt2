#include "gtest/gtest.h"
#include "Wektor.h"

TEST(Wektor, pustyKonstruktor) {
    Wektor<2> wektor;
    EXPECT_EQ(wektor[0], 0);
    EXPECT_EQ(wektor[1], 0);
}

TEST(Wektor, argumentowyKonstruktor) {
    Wektor<3> wektor({3, -99, 2});
    EXPECT_EQ(wektor[0], 3);
    EXPECT_EQ(wektor[1], -99);
    EXPECT_EQ(wektor[2], 2);
}

TEST(Wektor, dodawanie) {
    Wektor<2> wek1({2, 2});
    Wektor<2> wek2({1, 5});
    Wektor<2> wynik({3, 7});
    EXPECT_TRUE(wek1 + wek2 == wynik);
}

TEST(Wektor, dodawanieExtra) {
    Wektor<2> wek1({2, 2});
    Wektor<2> wek2({-2, -2});
    Wektor<2> wynik({0, 0});
    wek1 += wek2;
    EXPECT_TRUE(wek1 ==  wynik);
}

TEST(Wektor, odejmowanie) {
    Wektor<2> wek1({-5, 10});
    Wektor<2> wek2({5, 10});
    Wektor<2> wynik({-10, 0});
    wek1 = wek1 - wek2;
    EXPECT_TRUE(wek1 == wynik);
}

TEST(Wektor, odejmowanieExtra) {
    Wektor<2> wek1({-5, 10});
    Wektor<2> wek2({5, 10});
    Wektor<2> wynik({-10, 0});
    wek1 -= wek2;
    EXPECT_TRUE(wek1 == wynik);
}

TEST(Wektor, mnozeniePrzezStala) {
    Wektor<2> wektor({2, 3});
    double stala = -3;
    Wektor<2> wynik({-6, -9});
    wektor = wektor * stala;
    EXPECT_TRUE(wektor == wynik);
}

TEST(Wektor, dystansMiedzyWektorami) {
    Wektor<1> wek1({5});
    Wektor<1> wek2({2});
    EXPECT_EQ(dystansMiedzyDwomaWektorami(wek1, wek2), 3);
}



