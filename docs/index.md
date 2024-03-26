# Vulcano

## Cenário 

O vulcão está numa fase ativa e no interior da cratera existe um lago de lava a temperaturas altíssimas emanando gases tóxicos para qualquer ser vivo. A tua tarefa é construir um robot capaz de se aproximar da cratera e tirar alguns parâmetros através de sensores.

## Desafio

O robot terá de subir uma rampa no final da qual existe uma fonte de radiação infravermelha (700 nm ~ 1100 nm) e de calor. A rampa tem um comprimento entre 3,5 metros e 5 metros por 95 cm de largura e a sua superfície é revestida por um material imitando a escoada lávica de um vulcão, com uma inclinação de aproximadamente 15º. 
No início da rampa existe uma linha de partida/chegada e no cimo da rampa uma outra linha, de cor vermelha, laranja ou amarela, que indicará o ponto onde o robot deverá inverter a marcha, descendo a rampa.

![Vulcano](https://raw.githubusercontent.com/Robotics-and-AI-Group-of-UAc/Vulcano/main/img/rampa.png)

O desafio será dividido em duas categorias, com pontuações de acordo com as tarefas que o robô deve desempenhar:

### Iniciante (Nível I)
Um desafio com programação mais simples e em que a sinalização das leituras dos sensores é feita com um led. 

- Ao atingir o topo da rampa e parar na linha vermelha - 5 pontos
- Sinalizar a leitura da cor da linha no topo da rampa - o led pisca três vezes - o robô para durante cinco segundos - 5 pontos
- Regressar ao ponto de partida após atingir a linha vermelha - 5 pontos
- Durante a subida:
    - Sinalizar a leitura de um ponto quente na rampa - o led deve piscar uma vez - o robô para durante cinco segundos - 5 pontos

### Avançado (Nível II)
Um desafio com programação mais complexa que implica a comunicação do robô com um servidor através do protocolo MQTT.
- Ao atingir o topo da rampa e parar na linha vermelha - 5 pontos
- Sinalizar a leitura da cor da linha no topo da rampa - o led pisca três vezes - o robô para durante cinco segundos - 5 pontos 
- Regressar ao ponto de partida após atingir a linha vermelha - 5 pontos
- Durante a subida:
    - Enviar continuamente uma leitura de temperatura e/ou humidade para um servidor MQTT - 5 pontos
    - Enviar uma leitura da temperatura do ponto quente para um servidor MQTT - para o robô durante cinco segundos - 5 pontos

    
## Regras

1. As equipas podem ser constituídas por um máximo de 3 alunos e um tutor. As equipas serão divididas em dois grupos em função das médias de idade dos elementos das mesmas, sem contar com o tutor. A idade mínima dos elementos da equipa é de 9 anos. 
    - Grupo 1 - média de idades não ultrapassa os 16 anos - o elemento mais velho da equipa tem menos de 18 anos;                         
    - Grupo 2 - média de idades é superior a 16 anos - o elemento mais velho da equipa não pode ter mais de 23 anos;

2. O robô utilizado por cada equipa deverá ter no máximo 30 cm de comprimento e 25 de largura e ser completamente autónomo. Deverá ser maioritariamente desenvolvido pelas equipas. Não serão permitidos produtos comerciais ou kits nos quais os alunos não tenham participado no seu desenvolvimento. A organização disponibilizará um robô tipo que pode ser alterado pelas equipas durante o período de montagem e durante o período de prova. 

3. O robô poderá ser equipado com qualquer tipo de roda, wheg ou um misto das duas. Não serão permitidos sistemas que usem lagartas nem qualquer tipo de roda ou wheg comercial. São permitidos robôs que usem pernas, desde que estas tenham sido produzidas pelas próprias equipas.

4. O robô pode ser equipado com qualquer tipo de sensor que lhe permita orientar o seu movimento na rampa e deverá estar equipado com sensores e led de acordo com a descrição do desafio.

5. Cada equipa poderá fazer um máximo de três tentativas para completar a prova, escolhendo no final qual a tentativa que pretende validar. A pontuação de cada tentativa não acumula com nenhuma das outras tentativas.

6. Cada tentativa terá um tempo máximo de cinco minutos. Durante este período as equipas são livres de recomeçar o desafio. Após cada recomeço a pontuação retorna a zero. Para que uma tentativa possa ser validada o robô terá de ter realizado um mínimo de 15 pontos.

7. As equipas devem fazer uma pequena apresentação final - máximo de 5 minutos - enumerando as alterações e/ou inovações feitas ao robô durante os dias do festival e o seu enquadramento no desafio. Esta apresentação será avaliada pelo júri numa escala de 1 a 5, sendo 5 o valor mais alto, de acordo com os seguintes critérios:
    - Alterações/inovações efetuadas - 2 pontos
    - Execução técnica da alteração/inovação - 2 pontos
    - Valor técnico da alteração/inovação - 1 ponto

8. Durante os dias em que decorre o festival, as equipas serão avaliadas pelo júri numa escala de 1 a 5, sendo 5 o valor mais alto, no que aos seguintes parâmetros diz respeito:

    - Organização da equipa e espaço de trabalho - 1 ponto
    - Trabalho de equipa - 2 pontos
    - Fairplay - 2 pontos

9. Os casos omissos e as dúvidas de interpretação deste regulamento serão resolvidos pelo júri.



____________________________
## Software

<a href="https://robotics-and-ai-group-of-uac.github.io/Vulcano/software.html"> Software a instalar </a>
