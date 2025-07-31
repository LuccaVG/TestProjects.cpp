#include <iostream>
#include <string>
#include <bitset>
#include <cctype>
using namespace std;

// Funcao para converter numero decimal para binario
string decimalParaBinario(int numero) {
    if (numero == 0) return "0";
    
    string binario = "";
    int temp = numero;
    
    // Converte o numero usando divisoes sucessivas por 2
    while (temp > 0) {
        binario = (temp % 2 == 0 ? "0" : "1") + binario;
        temp = temp / 2;
    }
    
    return binario;
}

// Funcao para converter binario para decimal
int binarioParaDecimal(string binario) {
    int decimal = 0;
    int potencia = 1; // Comeca com 2^0 = 1
    
    // Le o binario da direita para esquerda
    for (int i = binario.length() - 1; i >= 0; i--) {
        if (binario[i] == '1') {
            decimal += potencia; // Adiciona 2^posicao se o bit for 1
        }
        potencia *= 2; // Proxima potencia de 2
    }
    
    return decimal;
}

// Funcao para converter caractere para binario (ASCII)
string caractereParaBinario(char c) {
    int ascii = (int)c; // Obtem o valor ASCII do caractere
    return decimalParaBinario(ascii);
}

// Funcao para converter binario para caractere (ASCII)
char binarioParaCaractere(string binario) {
    int ascii = binarioParaDecimal(binario);
    return (char)ascii; // Converte o valor ASCII de volta para caractere
}

// Funcao para exibir o menu principal
void exibirMenu() {
    cout << "\n========== CALCULADORA DE BITS ==========" << endl;
    cout << "Escolha uma opcao:" << endl;
    cout << "1 - Decimal para Binario" << endl;
    cout << "2 - Binario para Decimal" << endl;
    cout << "3 - Numero para Binario" << endl;
    cout << "4 - Binario para Numero" << endl;
    cout << "5 - Texto para Binario" << endl;
    cout << "6 - Binario para Texto" << endl;
    cout << "0 - Sair" << endl;
    cout << "==========================================" << endl;
    cout << "Digite sua opcao: ";
}

int main() {
    int opcao;
    
    do {
        exibirMenu();
        cin >> opcao;
        
        switch (opcao) {
            case 1: {
                // Conversao: Decimal -> Binario (com detalhes)
                int numero;
                cout << "Digite um numero decimal: ";
                cin >> numero;
                
                if (numero < 0) {
                    cout << "Por favor, digite apenas numeros positivos." << endl;
                } else if (numero == 0) {
                    cout << "\n--- DETALHES DA CONVERSAO ---" << endl;
                    cout << "Numero decimal: 0" << endl;
                    cout << "Em binario: 0" << endl;
                    cout << "Explicacao: 0 ja e 0 em binario" << endl;
                    cout << "Verificacao com bitset: " << bitset<8>(numero) << endl;
                } else {
                    string resultado = decimalParaBinario(numero);
                    
                    cout << "\n--- DETALHES DA CONVERSAO ---" << endl;
                    cout << "Numero decimal: " << numero << endl;
                    cout << "Em binario: " << resultado << endl;
                    cout << "Verificacao com bitset (8 bits): " << bitset<8>(numero) << endl;
                    cout << "Verificacao com bitset (16 bits): " << bitset<16>(numero) << endl;
                    
                    // Mostra informacoes adicionais
                    cout << "\nInformacoes adicionais:" << endl;
                    cout << "Numero de bits necessarios: " << resultado.length() << endl;
                    cout << "Maior potencia de 2: 2^" << (resultado.length() - 1) << " = " << (1 << (resultado.length() - 1)) << endl;
                    
                    // Informacao ASCII se for um valor valido
                    if (numero <= 127) {
                        cout << "Como caractere ASCII: '" << (char)numero << "'" << endl;
                    } else {
                        cout << "Valor muito grande para ASCII padrao (max 127)" << endl;
                    }
                }
                break;
            }
            
            case 2: {
                // Conversao: Binario -> Decimal (com detalhes)
                string binario;
                cout << "Digite um numero binario: ";
                cin >> binario;
                
                // Verifica se a string contem apenas 0s e 1s
                bool valido = true;
                for (char c : binario) {
                    if (c != '0' && c != '1') {
                        valido = false;
                        break;
                    }
                }
                
                if (!valido) {
                    cout << "Erro! Digite apenas 0s e 1s." << endl;
                } else {
                    int resultado = binarioParaDecimal(binario);
                    
                    cout << "\n--- DETALHES DA CONVERSAO ---" << endl;
                    cout << "Numero binario: " << binario << endl;
                    cout << "Em decimal: " << resultado << endl;
                    
                    // Mostra informacoes adicionais
                    cout << "\nInformacoes adicionais:" << endl;
                    cout << "Numero de bits: " << binario.length() << endl;
                    cout << "Valor maximo representavel com " << binario.length() << " bits: " << ((1 << binario.length()) - 1) << endl;
                    
                    // Conta quantos bits estao ligados (1s)
                    int bitsLigados = 0;
                    for (char c : binario) {
                        if (c == '1') bitsLigados++;
                    }
                    cout << "Bits ligados (1s): " << bitsLigados << "/" << binario.length() << endl;
                    cout << "Bits desligados (0s): " << (binario.length() - bitsLigados) << "/" << binario.length() << endl;
                    
                    // Informacao ASCII se for um valor valido
                    if (resultado <= 127) {
                        cout << "Como caractere ASCII: '" << (char)resultado << "'" << endl;
                    } else {
                        cout << "Valor muito grande para ASCII padrao (max 127)" << endl;
                    }
                }
                break;
            }
            
            case 3: {
                // Conversao: Numero -> Binario (com detalhes do processo)
                int numero;
                cout << "Digite um numero decimal: ";
                cin >> numero;
                
                if (numero < 0) {
                    cout << "Por favor, digite apenas numeros positivos." << endl;
                } else if (numero == 0) {
                    cout << "Numero decimal: 0" << endl;
                    cout << "Em binario: 0" << endl;
                    cout << "Processo: 0 ja e 0 em binario" << endl;
                } else {
                    string resultado = decimalParaBinario(numero);
                    
                    cout << "Numero decimal: " << numero << endl;
                    cout << "Em binario: " << resultado << endl;
                    cout << "Verificacao com bitset: " << bitset<16>(numero) << endl;
                    
                    // Mostra o processo de conversao passo a passo
                    cout << "\nProcesso de conversao (divisoes por 2):" << endl;
                    int temp = numero;
                    string processo = "";
                    
                    while (temp > 0) {
                        int resto = temp % 2;
                        cout << temp << " ÷ 2 = " << temp/2 << " resto " << resto << endl;
                        processo = to_string(resto) + processo;
                        temp = temp / 2;
                    }
                    
                    cout << "Lendo os restos de baixo para cima: " << resultado << endl;
                    
                    // Informacoes adicionais
                    cout << "\nInformacoes adicionais:" << endl;
                    cout << "Numero de bits necessarios: " << resultado.length() << endl;
                    
                    // Informacao ASCII se for um valor valido
                    if (numero <= 127) {
                        cout << "Como caractere ASCII: '" << (char)numero << "'" << endl;
                    } else {
                        cout << "Valor muito grande para ASCII padrao (max 127)" << endl;
                    }
                }
                break;
            }
            
            case 4: {
                // Conversao: Binario -> Numero (com detalhes do processo)
                string binario;
                cout << "Digite um numero binario: ";
                cin >> binario;
                
                // Verifica se a string contem apenas 0s e 1s
                bool valido = true;
                for (char c : binario) {
                    if (c != '0' && c != '1') {
                        valido = false;
                        break;
                    }
                }
                
                if (!valido) {
                    cout << "Erro! Digite apenas 0s e 1s." << endl;
                } else {
                    int resultado = binarioParaDecimal(binario);
                    
                    cout << "Numero binario: " << binario << endl;
                    cout << "Em decimal: " << resultado << endl;
                    
                    // Mostra o processo de conversao passo a passo
                    cout << "\nProcesso de conversao (potencias de 2):" << endl;
                    int decimal = 0;
                    int potencia = 1;
                    
                    // Mostra cada posicao e sua contribuicao
                    for (int i = binario.length() - 1; i >= 0; i--) {
                        int posicao = binario.length() - 1 - i;
                        char bit = binario[i];
                        
                        cout << "Posicao " << posicao << ": " << bit << " × 2^" << posicao << " = ";
                        
                        if (bit == '1') {
                            cout << "1 × " << potencia << " = " << potencia << endl;
                            decimal += potencia;
                        } else {
                            cout << "0 × " << potencia << " = 0" << endl;
                        }
                        
                        potencia *= 2;
                    }
                    
                    cout << "Soma total: " << decimal << endl;
                    
                    // Informacoes adicionais
                    cout << "\nInformacoes adicionais:" << endl;
                    cout << "Numero de bits: " << binario.length() << endl;
                    
                    // Conta quantos bits estao ligados (1s)
                    int bitsLigados = 0;
                    for (char c : binario) {
                        if (c == '1') bitsLigados++;
                    }
                    cout << "Bits ligados (1s): " << bitsLigados << "/" << binario.length() << endl;
                    
                    // Informacao ASCII se for um valor valido
                    if (resultado <= 127) {
                        cout << "Como caractere ASCII: '" << (char)resultado << "'" << endl;
                    } else {
                        cout << "Valor muito grande para ASCII padrao (max 127)" << endl;
                    }
                }
                break;
            }
            
            case 5: {
                // Conversao: Texto -> Binario (com detalhes)
                string texto;
                cout << "Digite um texto: ";
                cin.clear();
                while (cin.get() != '\n');  // Limpa o buffer
                getline(cin, texto);
                
                cout << "\n--- DETALHES DA CONVERSAO ---" << endl;
                cout << "Texto: \"" << texto << "\"" << endl;
                cout << "Numero de caracteres: " << texto.length() << endl;
                cout << "Total de bits necessarios: " << (texto.length() * 8) << " bits" << endl;
                cout << "\nConversao caractere por caractere:" << endl;
                
                string binarioCompleto = "";
                for (int i = 0; i < texto.length(); i++) {
                    char c = texto[i];
                    string binario = caractereParaBinario(c);
                    binarioCompleto += binario + " ";
                    
                    cout << "Posicao " << i+1 << ": '" << c << "' (ASCII " << (int)c << ") -> " << binario;
                    cout << " (8 bits: " << bitset<8>((int)c) << ")" << endl;
                }
                
                cout << "\nTexto completo em binario (separado por espacos):" << endl;
                cout << binarioCompleto << endl;
                break;
            }
            
            case 6: {
                // Conversao: Binario -> Texto (com detalhes)
                cout << "Digite sequencias de binario separadas por espaco:" << endl;
                cout << "(Exemplo: 01001000 01100101 01101100 01101100 01101111)" << endl;
                cout << "Cada sequencia deve ter 8 bits para representar um caractere ASCII" << endl;
                
                string linha;
                cin.clear();
                while (cin.get() != '\n');  // Limpa o buffer
                getline(cin, linha);
                
                string palavra = "";
                string resultado = "";
                int posicao = 1;
                
                cout << "\n--- DETALHES DA CONVERSAO ---" << endl;
                cout << "Entrada: \"" << linha << "\"" << endl;
                cout << "\nConversao sequencia por sequencia:" << endl;
                
                // Processa cada caractere da linha
                for (int i = 0; i <= linha.length(); i++) {
                    if (i == linha.length() || linha[i] == ' ') {
                        // Fim de uma palavra binaria
                        if (!palavra.empty()) {
                            // Verifica se a palavra contem apenas 0s e 1s
                            bool valido = true;
                            for (char c : palavra) {
                                if (c != '0' && c != '1') {
                                    valido = false;
                                    break;
                                }
                            }
                            
                            if (valido) {
                                int decimal = binarioParaDecimal(palavra);
                                char caractere = binarioParaCaractere(palavra);
                                resultado += caractere;
                                
                                cout << "Sequencia " << posicao << ": " << palavra;
                                cout << " -> Decimal: " << decimal;
                                cout << " -> ASCII: '" << caractere << "'";
                                
                                if (decimal >= 32 && decimal <= 126) {
                                    cout << " [IMPRIMIVEL]" << endl;
                                } else {
                                    cout << " [NAO IMPRIMIVEL/CONTROLE]" << endl;
                                }
                                
                            } else {
                                cout << "ERRO na sequencia " << posicao << ": " << palavra << " (contem caracteres invalidos)" << endl;
                            }
                            palavra = "";
                            posicao++;
                        }
                    } else {
                        palavra += linha[i];
                    }
                }
                
                cout << "\nTexto resultante: \"" << resultado << "\"" << endl;
                cout << "Total de caracteres decodificados: " << resultado.length() << endl;
                break;
            }
            
            case 0:
                cout << "Saindo da calculadora de bits..." << endl;
                break;
                
            default:
                cout << "Erro! Opcao invalida. Tente novamente." << endl;
                break;
        }
        
        if (opcao != 0) {
            cout << "\nPressione Enter para continuar...";
            cin.clear();
            while (cin.get() != '\n');  // Limpa o buffer até encontrar newline
        }
        
    } while (opcao != 0);
    
    return 0;
}
