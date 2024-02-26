# Exibição de Emoticons em um Display de LED com Arduino

![Blue](https://github.com/EduardoDosSantosFerreira/blue-cpp/blob/main/blue.png)

O código fornecido implementa a exibição de três emoticons (feliz, normal e triste) em um display de LED utilizando um Arduino e um registro de deslocamento (74HC595). Cada emoticon é exibido por um curto período de tempo e é controlado por um potenciômetro que ajusta a velocidade de exibição.

## Componentes Utilizados

- Arduino board
- Registro de deslocamento 74HC595
- Display de LED de 8x8 (ou matrizes de LED)
- Potenciômetro

## Funcionalidades do Código

1. **Configuração dos Pinos e Comunicação Serial**

   - Os pinos para o registro de deslocamento (data, store, shift) são configurados como saídas.
   - Inicializa a comunicação serial para depuração.

2. **Leitura do Potenciômetro**

   - Uma função `poti` é definida para ler o valor do potenciômetro.

3. **Exibição dos Emoticons**

   - Funções `happy`, `normal` e `sad` são definidas para exibir os emoticons feliz, normal e triste, respectivamente.
   - Cada emoticon é exibido por um curto período de tempo e é controlado pela leitura do potenciômetro.

4. **Loop de Exibição**

   - O loop principal chama sequencialmente as funções para exibir os emoticons feliz, normal, triste, normal, em um ciclo contínuo.

## Considerações Finais

Esse projeto demonstra como controlar um display de LED utilizando um registro de deslocamento com um Arduino. O uso do potenciômetro permite ajustar a velocidade de exibição dos emoticons. Essa abordagem pode ser expandida para exibir outros tipos de imagens ou padrões em displays de LED, proporcionando uma experiência visual interessante.
