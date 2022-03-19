#pragma once
#include <random>
#include <iostream>
#include <cmath>

void ass()
{
    uint64_t p, q, n, t, e, d;
    
    // Cоздание открытого и секретного ключей
    
    // 1. Выбираются два различных случайных простых числа p и q заданного размера
    // 2. Вычисляется их произведение n = p ⋅ q, которое называется модулем.
    
    // 3. Вычисляется значение функции Эйлера от числа n: φ(n) = (p−1)⋅(q−1)
    // t = ( p - 1 ) * ( q - 1 );
    
    // 4. Выбирается целое число e ( 1 < e < φ(n) ), взаимно простое со значением функции Эйлера (t)
    //	  Число e называется открытой экспонентой
    // e = calculateE( t );
    
    // 5. Вычисляется число d, мультипликативно обратное к числу e по модулю φ(n), то есть число, удовлетворяющее сравнению:
    //    d ⋅ e ≡ 1 (mod φ(n))
    // d = calculateD( e, t );
    
    // 6. Пара {e, n} публикуется в качестве открытого ключа RSA
    
    // 7. Пара {d, n} играет роль закрытого ключа RSA и держится в секрете
    
    /*for (uint64_t i = 0; i < msg.length(); i++)
    {
        encryptedText[i] = encrypt( msg[i], e, n);
    }*/
    
    /*for ( uint64_t i = 0; i < msg.length(); i++ )
    {
        printf( "%c", (char)encryptedText[i] );
    }*/
    
    /*for (uint64_t i = 0; i < msg.length(); i++)
    {
        decryptedText[i] = decrypt(encryptedText[i], d, n);
    }*/
    
    /*for (uint64_t i = 0; i < msg.length(); i++)
    {
        printf( "%c", (char)decryptedText[i] );
    }*/
}

bool IsPrime(uint64_t prime)
{
    uint64_t j = (uint64_t)sqrt((long double)prime);
    
    for (uint64_t i = 2; i <= j; i++)
    {
        if (prime % i == 0)
            return false;
    }
    
    return true;
}

uint64_t GetRandomPrime(uint64_t max)
{
    std::random_device r;
    std::default_random_engine eng(r());
    uint64_t m = std::uniform_int_distribution<uint64_t>(0, max)(eng);

    while(!IsPrime(m++));
    return m;
}

uint64_t CommonDivisor(uint64_t e, uint64_t t)
{
    while(e > 0)
    {
        uint64_t tmp = e;
        e = t % e;
        t = tmp;
    }
    
    return t;
}

uint64_t CalcE(uint64_t t)
{
    for(uint64_t e = 2; e < t; e++)
    {
        if (CommonDivisor(e, t) == 1)
            return e;
    }
    
    return -1;
}

uint64_t CalcD(uint64_t e, uint64_t t)
{   
    uint64_t k = 1;
    
    while(true)
    {
        k += t;    
        if (k % e == 0) return (k / e);
    }
}

uint64_t Encrypt(uint64_t i, uint64_t e, uint64_t n)
{
    uint64_t current, result;
    
    current = i - 97;
    result = 1;
    
    for ( uint64_t j = 0; j < e; j++ )
    {
        result = result * current;
        result = result % n;
    }
    
    return result;
}

uint64_t Decrypt(uint64_t i, uint64_t d, uint64_t n)
{
    uint64_t current = i, result = 1;
    
    for (uint64_t j = 0; j < d; j++)
        result *= current % n;
    
    return result + 97;
}
