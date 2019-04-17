#include <iostream>
#include <list>
#include "taluno.h"
#include "tprofessor.h"
#include<cstring>
#include<string>
#include "tpessoa.h"
#include "tlista.h"

using std::string;

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	bool sair = false;
	
	TLista *listaptrPessoa = new TLista();
	int id_pessoa = 0;
	
	TPessoa *ptrPessoa;
	
	//TAluno *listAluno[10];
	TAluno *ptrAluno;
	
	//int id_aluno = 0;
	//int id_professor = 0;
	//TProfessor *listProfessor[10];
	TProfessor *ptrProfessor;
	
	do{
		char opc;
		cout << "DIGITE:\n"
			 << "0 - Sair\n"
			 << "1 - cadastrar aluno\n"
			 << "2 - cadastrar professor\n"
			 << "3 - mostrar professores\n"
			 << "4 - mostrar alunos\n"
			 << "5 - visualizar Pessoa especifica\n"
			 << "6 - Deletar da lista\n"
			 << "7 - Imprimir lista\n";
			 
		cin >> opc;
		switch(opc){
			case '0':{
			
				sair = true;
				break;
			}
			case '1':{
				if(id_pessoa <= 100){
					
					cin.ignore();
					
					ptrAluno = new TAluno();
					
					string nome;
					cout << "Nome Aluno: ";
					cout.flush();
					getline(cin, nome);
					
					string cpf;
					cout << "\n\nCPF: ";
					cout.flush();
					getline(cin, cpf);
					
					string endereco;
					cout << "\n\nEndereco: ";
					cout.flush();
					getline(cin, endereco);
					
					float valor;
					cout << "\n\nValor da mensalidade: ";
					cin >> valor;
					
					ptrAluno -> Set_nome(nome);  
					ptrAluno -> Set_codigoMatricula(id_pessoa +1);
					ptrAluno -> Set_endereco(endereco);      
					ptrAluno -> Set_numeroCPF(cpf);
					ptrAluno -> Set_valorMensalidade(valor);
					
					listaptrPessoa -> Add(ptrAluno);
					id_pessoa+= 1;
				}
				else{
					cout << "Lista cheia\n\n";
				}
				break;
			}
			case '2':{
				if (id_pessoa <= 100){
					
					cin.ignore();
					
					ptrProfessor = new TProfessor();
					
					string nome;
					cout << "Nome do professor: ";
					cout.flush();
					getline(cin, nome);
					
					string cpf;
					cout << "\n\nCPF: ";
					cout.flush();
					getline(cin, cpf);
					
					string endereco;
					cout << "\n\nEndereco: ";
					cout.flush();
					getline(cin, endereco);
					
					float valor;
					cout << "\n\nSalario: ";
					cin >> valor;
					
					ptrProfessor -> Set_nome(nome);
					ptrProfessor -> Set_codigoRegistro(id_pessoa +1);
					ptrProfessor -> Set_endereco(endereco);
					ptrProfessor -> Set_numeroCPF(cpf);
					ptrProfessor -> Set_valorSalario(valor);
					
					listaptrPessoa -> Add(ptrProfessor);
					id_pessoa++;
				}
				else{
					cout << "Lista cheia\n\n";
				}
				break;
			}
			case '3':{
				int cont_posicao = 0;
				
				listaptrPessoa -> Clear_read();
				
				listaptrPessoa -> Clear_read();
				ptrPessoa = (TPessoa *) listaptrPessoa-> Get_nextItem();
				while(ptrPessoa != NULL){
					
					if (ptrPessoa -> Get_tipoPessoa() == TIPO_PROFESSOR){
						ptrProfessor = (TProfessor *)ptrPessoa;
						cout <<" ----------------------"<< cont_posicao + 1 <<"------------------------"
							<< "\n   nome: "<< ptrProfessor ->  Get_nome()
							<< "\n   registro: " << ptrProfessor ->  Get_codigoRegistro()
							<< "\n   CPF: " << ptrProfessor ->  Get_numeroCPF()
							<< "\n   Endereco: " << ptrProfessor ->  Get_endereco()
							<< "\n   Salario: " << ptrProfessor ->  Get_valorSalario()
							<<"\n-------------------------------------------------\n\n";
						
						cont_posicao ++;
					}
					ptrPessoa =(TPessoa *) listaptrPessoa -> Get_nextItem();
				}
				
				
				break;
			}
			case '4':{
				int cont_posicao = 0;
				
				listaptrPessoa -> Clear_read();
				ptrPessoa = (TPessoa *) listaptrPessoa-> Get_nextItem();
				while(ptrPessoa != NULL){
					
					if (ptrPessoa->Get_tipoPessoa() == TIPO_ALUNO){
						ptrAluno = (TAluno *)ptrPessoa;
						cout <<" ----------------------"<< cont_posicao + 1 <<"------------------------"
							<< "\n   nome: "<< ptrAluno ->  Get_nome()
							<< "\n   registro: " << ptrAluno ->  Get_codigoMatricula()
							<< "\n   CPF: " << ptrAluno ->  Get_numeroCPF()
							<< "\n   Endereco: " << ptrAluno ->  Get_endereco()
							<< "\n   Mensalidade: " << ptrAluno ->  Get_valorMensalidade()
							<<"\n-------------------------------------------------\n\n";
						
						cont_posicao ++;
					}
					ptrPessoa =(TPessoa *) listaptrPessoa-> Get_nextItem();
				}
				
				
				break;	
			}
			case '5':{
				int posicao;
				cout<<"Digite a posição da lista da pessoa\n";
				cin >> posicao;
				ptrPessoa = (TPessoa *) listaptrPessoa-> Get_Item(posicao);
				if(ptrPessoa != NULL){
					if (ptrPessoa->Get_tipoPessoa() == TIPO_ALUNO){
						ptrAluno = (TAluno *)ptrPessoa;
						cout <<" ---------------------------------------------------"
							<< "\n   nome: "<< ptrAluno ->  Get_nome()
							<< "\n   registro: " << ptrAluno ->  Get_codigoMatricula()
							<< "\n   CPF: " << ptrAluno ->  Get_numeroCPF()
							<< "\n   Endereco: " << ptrAluno ->  Get_endereco()
							<< "\n   Mensalidade: " << ptrAluno ->  Get_valorMensalidade()
							<<"\n-------------------------------------------------\n\n";
					}
					else{
						ptrProfessor = (TProfessor *)ptrPessoa;
						cout <<" ----------------------------------------------------"
							<< "\n   nome: "<< ptrProfessor ->  Get_nome()
							<< "\n   registro: " << ptrProfessor ->  Get_codigoRegistro()
							<< "\n   CPF: " << ptrProfessor ->  Get_numeroCPF()
							<< "\n   Endereco: " << ptrProfessor ->  Get_endereco()
							<< "\n   Salario: " << ptrProfessor ->  Get_valorSalario()
							<<"\n-------------------------------------------------\n\n";
					}
					
					cout<<"0- Voltar\n"
						<<"1- Deletar\n";
					cin >> opc;
					
					switch(opc){
						case '1':{
							ptrPessoa = (TPessoa *) listaptrPessoa->Remove_item(ptrPessoa);
							if(ptrPessoa != NULL){			
								delete(ptrPessoa);
							}
							break;
						}
					}
				}
				break;
			}
			case '6':{
				int posicao;
				cout<<"Digite a posição para exclusão\n";
				cin >> posicao;
				
				ptrPessoa = (TPessoa *) listaptrPessoa->Remove_item(posicao);
				if(ptrPessoa != NULL){			
					delete(ptrPessoa);
				}
				
				break;
			}
			case '7':{
				
				int cont_posicao = 0;
				
				listaptrPessoa -> Clear_read();
				ptrPessoa = (TPessoa *) listaptrPessoa-> Get_nextItem();
				while(ptrPessoa != NULL){
					
					if (ptrPessoa->Get_tipoPessoa() == TIPO_ALUNO){
						ptrAluno = (TAluno *)ptrPessoa;
						cout <<" ----------------------"<< cont_posicao + 1 <<"------------------------"
							<< "\n   nome: "<< ptrAluno ->  Get_nome()
							<< "\n   registro: " << ptrAluno ->  Get_codigoMatricula()
							<< "\n   CPF: " << ptrAluno ->  Get_numeroCPF()
							<< "\n   Endereco: " << ptrAluno ->  Get_endereco()
							<< "\n   Mensalidade: " << ptrAluno ->  Get_valorMensalidade()
							<<"\n-------------------------------------------------\n\n";
					}
					else{
						ptrProfessor = (TProfessor *)ptrPessoa;
						cout <<" ----------------------"<< cont_posicao + 1 <<"------------------------"
							<< "\n   nome: "<< ptrProfessor ->  Get_nome()
							<< "\n   registro: " << ptrProfessor ->  Get_codigoRegistro()
							<< "\n   CPF: " << ptrProfessor ->  Get_numeroCPF()
							<< "\n   Endereco: " << ptrProfessor ->  Get_endereco()
							<< "\n   Salario: " << ptrProfessor ->  Get_valorSalario()
							<<"\n-------------------------------------------------\n\n";
					}
					cont_posicao ++;
					ptrPessoa =(TPessoa *) listaptrPessoa-> Get_nextItem();
				}
				
				break;
			}
			default:{
					cout << "Opcao invalida\n\n";
					break;
			}
				
				
			
		}
		
	}while(!sair);
	
	return 0;
}
