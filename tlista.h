#include <iostream>
#include "tpessoa.h"

#ifndef TLISTA_H
#define TLISTA_H

struct TipoNo{
	void *ptrItem;
	TipoNo *prox;
};

class TLista
{
	private:
		int lenght;
		TipoNo *primeiroItem;
		TipoNo *ultimoItem;
		TipoNo *ptrProxNo;
		
	public:
		TLista(){
			primeiroItem = NULL;
			ultimoItem = NULL;
			ptrProxNo = NULL;
			lenght = 0;
		}
		~TLista(){
			TipoNo *noAuxiliar;
			for (int i=0; i < lenght; i++){
				noAuxiliar = primeiroItem;
				primeiroItem = primeiroItem -> prox;
				delete(noAuxiliar);
			}
		}
		void Add(void *prtItem){
			TipoNo *NovoNo = new TipoNo;
			NovoNo->ptrItem = prtItem;
			NovoNo->prox =NULL;
			if(primeiroItem == NULL){
				primeiroItem = NovoNo;
				ultimoItem = NovoNo;
			}
			else{

				ultimoItem -> prox = NovoNo;
				
				ultimoItem = NovoNo;
				
			}
			lenght++;
		}
		void Clear_read(){
			ptrProxNo = primeiroItem;
		}
		void *Get_nextItem(){
			if(ptrProxNo != NULL){
				TipoNo *ptrReturn = ptrProxNo;
				ptrProxNo = ptrProxNo->prox;
				
				return ptrReturn->ptrItem;
			}
			return NULL;
		}
		void *Get_Item(int pos){
			
			if(pos > 0 && pos <= lenght ){
				TipoNo *noAuxiliar = primeiroItem;
				for (int i=1; i < pos; i++){
					
					noAuxiliar = noAuxiliar->prox;
				}	
				return noAuxiliar->ptrItem;
			}
			
			return NULL;
		}
		void *Remove_item (void* ptrItem){
			TipoNo *noAuxiliar;
			TipoNo *noPosterior =  primeiroItem;
			void *ptrItemAux;
			for (int i=0; i < lenght; i++){
				if(noPosterior -> ptrItem== ptrItem){
					if (i == 0){
						primeiroItem = noPosterior->prox;
					}
					else{
						noAuxiliar -> prox =  noPosterior-> prox;
					}
					
					ptrItemAux = noPosterior -> ptrItem;
					lenght --;
					return ptrItemAux;
				}
				noAuxiliar = noPosterior;
				noPosterior = noPosterior -> prox;
			}
			
			return NULL;
		}
		void *Remove_item (int indice){
			TipoNo *noAuxiliar;
			TipoNo *noPosterior =  primeiroItem;
			void *ptrItemAux;
			for (int i=0; i < lenght; i++){
				if(i+1  == indice){
					if (i == 0){
						primeiroItem = noPosterior->prox;
					}
					else{
						noAuxiliar -> prox =  noPosterior-> prox;
					}
					ptrItemAux = noPosterior -> ptrItem;
					lenght--;
					return ptrItemAux;
				}
				noAuxiliar = noPosterior;
				noPosterior = noPosterior -> prox;
			}
			
			return NULL;
		}
		
	protected:
};

#endif
