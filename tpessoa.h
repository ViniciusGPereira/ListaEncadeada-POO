#ifndef TPESSOA_H
#define TPESSOA_H
#include<string>

using std::string;

enum TiposPessoas{
	TIPO_PROFESSOR,
	TIPO_ALUNO
};


class TPessoa
{
	
	protected:
		TiposPessoas tipo_da_pessoa;
	private:
		string nome;
		string endereco;
		string numeroCPF;
		
	public:
		float valorMensalidade;
		TPessoa();
		~TPessoa();
		TiposPessoas Get_tipoPessoa(){
			return tipo_da_pessoa;
		}
		void Set_nome(string nom){
			nome = nom;
		}
		string Get_nome(){
			return nome;
		}
		void Set_endereco(string ende){
			endereco = ende;
		}
		string Get_endereco(){
			return endereco;
		}
		void Set_numeroCPF(string cpf){
			numeroCPF = cpf;
		}
		string Get_numeroCPF(){
			return numeroCPF;
		}
	protected:
};

#endif
