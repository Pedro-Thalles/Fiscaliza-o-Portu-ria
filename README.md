INSTRUÇÕES PARA RODAR:

No terminal, deve-se passar os argumentos de entrada e saida. Ambos devem ser arquivos txt.

O arquivo de entrada deve seguir esse formato:

10/n
QOZJ7913219 34.699.211/9365-11 13822
FCCU4584578 50.503.434/5731-28 16022
KTAJ0603546 20.500.522/6013-58 25279
ZYHU3978783 43.172.263/4442-14 24543
IKQZ7582839 51.743.446/1183-18 12160
HAAZ0273059 25.699.428/4746-79 16644
APCL8876543 90.123.456/0001-01 32100
MEDU1122333 11.222.333/4444-55 18500
TGBX9876543 65.432.109/8765-43 27300
UASK0011223 77.888.999/1122-33 14950
5
QOZJ7913219 34.699.211/9365-11 16722
KTAJ0603546 20.500.522/6113-58 17842
IKQZ7582839 51.743.446/1113-18 18501
HAAZ0273059 25.699.428/4746-79 16000
APCL8876543 90.123.456/0001-01 30000


O primeiro bloco são as cargas cadastradas, com código, cnpj e peso em kg. O segundo bloco são de cargas selecionadas com suspeita de irregularidade.

As primeiras linhas da saída mostram as cargas com diferença de cnpj, e as próximas mostram as cargas com as maiores diferenças percentuais de peso acima de 10%

no exemplo acima, a saída fica assim:

KTAJ0603546:20.500.522/6013-58<->20.500.522/6113-58
IKQZ7582839:51.743.446/1183-18<->51.743.446/1113-18
QOZJ7913219:2900kg(21%)
