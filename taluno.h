#ifndef TALUNO_H
#define TALUNO_H
#include<string>
#include "tpessoa.h"

using std::string;

class TAluno : public TPessoa
{
	private:
		int codigoMatricula;
		float valorMensalidade;
	public:
		TAluno(){
			tipo_da_pessoa = TIPO_ALUNO;
		}
		~TAluno();
		
		void Set_codigoMatricula(int codigo){
			codigoMatricula = codigo;
		}
		int Get_codigoMatricula(){
			return codigoMatricula;
		}
		void Set_valorMensalidade(float valor){
			valorMensalidade = valor;
		}
		float Get_valorMensalidade(){
			return valorMensalidade;
		}
		
		

	protected:
};

#endif
