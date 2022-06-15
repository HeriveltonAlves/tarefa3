// Desafio técnico para Projetista de Sistemas Embracados - MOBIT 14/06/2022
// Candidato: Herivelton
//3. Produtor-Consumidor em C++

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <string>
#include <fstream>

std::mutex mtx;           // mutex for critical section
    char faixa;
static   char vel1[4];
static   char vel2[4];
   char vel3[4], vel[4];

void produtor()
{
    char buff[120];
    mtx.lock();
    std::cout << "Iniciando o produtor"<< std::endl;
    std::cout << "Recebe o arquivo xml"<< std::endl;

    std::ifstream fin2("input.xml"); // Abre arquivo para leitura
    while(fin2) // Enquanto não for fim de arquivo
    { fin2.getline(buff, 80); // Lê uma linha do arquivo
    std::cout << buff << '\n'; } // Exibe no vídeo
    faixa = buff[14];
    for(int i = 21; i <25; i++){
        vel1[i-21] = buff[i];}

    for(int i = 32; i<36; i++)
    {
        vel2[i-32] = buff[i];
    }
    for(int i = 43; i <47; i++)
    {
        vel3[i-43] = buff[i];
    }
    for(int i = 53; i <57; i++)
    {
        vel[i-53] = buff[i];
    }


    mtx.unlock();
}
void consumidor()
{
    mtx.lock();
    std::cout << "Iniciando o consumidor"<< std::endl;
    std::cout << "Apresenta os dados"<< std::endl;
    std::cout << "Faixa = "  << faixa << "\n";
    std::cout << "Velocidade 1 = "  << vel1 << " km/h\n";
    std::cout << "Velocidade 2 = "  << vel2 << " km/h\n";
    std::cout << "Velocidade 3 = "  << vel3 << " km/h\n";
    std::cout << "Velocidade 0 = "  << vel << " km/h\n";

    mtx.unlock();
}

int main()
{
    std::thread t1(produtor);
    t1.join();
    std::thread t2(consumidor);
    t2.join();

//    std::ifstream fin("input.xml"); // Abre arquivo para leitura
    //em modo texto
//    char ch;
    // Enquanto não for fim de arquivo:
//    while(fin.get(ch)) // lê um caracter do arquivo
//    std::cout << ch; // imprime o caracter no vídeo

    return 0;
}
