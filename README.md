Repositório para o Projeto 1 da disciplina Criptografia e Segurança de Redes

/************************************************************************/

Neste exercício você irá fazer um programa de criptografia simples na linguagem de
programação de sua escolha. Em seguida irá gerar alguns textos cifrados. Finalmente você vai
tentar criptoanalizar os textos cifrados de um outro grupo.

Por simplicidade, assuma que o alfabeto de entrada é {a-z, A-Z, 0-9} mais um caracter especial
representando o espaço em branco. O seu programa deverá implementar as seguintes funções:

1) De um texto em claro produza um cifrador de substituição alfabética. Em outras
palavras, a sua chave é uma regra de substituição para cada possivel caracter de entrada.

2) De um texto em claro produza um cifrador de transposição. Para que a encriptação seja
uniforme para todos os alunos, assuma que o cifrador vai operar num bloco de 8 caracteres.
Em outras palavras, você sempre fará a permuta dentro de um bloco de 8 caracteres.

3) De um texto em claro produza um cifrador de produto utilizando as funções anteriores.
Por simplicidade, assuma que o cifrador de substituição é usado primeiro. Depois o cifrador por
transposição é usado para cifrar o resultado intermediário, obtendo o texto cifrado final.

Gere um método de cifração com cada uma das tres funções (tres cifradores ao todo). Para cada método de
cifração (com uma chave fixa) cifre um texto em claro qualquer que contenha as palavras “computador” e
“segurança”. Cada texto deve conter pelo menos 1000 caracteres do tipo normal (não do tipo caligrafia manual).

Depois de produzir os textos cifrados com os tres métodos de cifração (com chaves diferentes),
projete métodos para obter o texto em claro original usando os textos cifrados obtidos. Comece
com o item mais simples (1), abaixo, e prossiga implementando os itens (2) e (3).

1) Desenvolva as suas próprias ferramentas ou use ferramentas ou scripts disponíveis para
criptoanalizar os textos cifrados.

2) Tente obter o texto em claro a partir do texto cifrado.

3) Tente obter a chave ou o alfabeto utilizado.

O que você precisa entregar:

a) Um programa que produza textos cifrados usando cada um dos tres métodos acima. A entrada
para o programa será um arquivo texto contendo o texto em claro e um outro arquivo texto
contendo a chave para cifração. A saída deverá ser um arquivo contendo o texto cifrado.

b) Um programa para produzir textos em claro usando cada um dos tres métodos acima. A
entrada para o programa será um arquivo texto contendo o texto cifrado e um outro
arquivo texto contendo a chave para decifração. A saída deverá ser um arquivo
contendo o texto em claro obtido da decifração.

c) Um programa para quebrar os cifradores que utilizem de cada método de cifração. A
entrada para este programa será um arquivo contendo o texto cifrado e, possivelmente, um
outro arquivo texto contendo uma lista de palavras que devem estar presentes no texto em
claro. A saída deverá ser um arquivo contendo o texto em claro e outro contendo a chave.