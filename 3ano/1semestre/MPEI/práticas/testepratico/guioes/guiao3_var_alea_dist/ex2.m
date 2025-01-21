% uma caixa contendo: 
% 90 notas de 5 Euros 
% 9 notas de 50 
% 1 de 100.

% a)
% S = {5,50,100}

% Valores possíveis da variável aleatória X (valores das notas)
X = [5, 50, 100];

% P(X = 5) = 90/100 = 0.9
% P(X = 50) = 9/100 = 0.09
% P(X = 100) = 1/100 = 0.01

% Probabilidades associadas a cada valor de X
P_X = [0.9, 0.09, 0.01];

% Plotar a função massa de probabilidade (FMP)
figure;

stem(X, P_X, 'filled', 'LineWidth', 1.5);
grid on;

% Personalizar o gráfico
xlabel('Valor da Nota (X)');
ylabel('Probabilidade P(X)');
title('Função Massa de Probabilidade de X');
xticks(X);
ylim([0 1.1]); % Ajuste para visualizar bem as probabilidades
