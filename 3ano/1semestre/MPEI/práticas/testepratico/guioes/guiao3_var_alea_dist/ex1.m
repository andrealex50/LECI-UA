% a)
% valores possiveis 1 a 6
X = 1:6;

% Probabilidades teóricas para cada valor de X
P = ones(1, 6) / 6; % matriz com 1 linha e 6 colunas

% b)
% Calculo da função de distribuição acumulada
FDA = cumsum(P);


% Criar o gráfico
figure;

% Gráfico da FMP
subplot(2, 1, 1); % Subplot 1 (primeira posição)
stem(X, P, 'filled', 'LineWidth', 1.5);
grid on;
xlabel('Face do dado (X)');
ylabel('Probabilidade P(X)');
title('Função Massa de Probabilidade (FMP)');
xticks(X);
ylim([0 0.2]);

% Gráfico da FDA
subplot(2, 1, 2); % Subplot 2 (segunda posição)
stairs([0 X], [0 FDA], 'LineWidth', 1.5); % Início em 0 para melhorar a visualização
grid on;
xlabel('Face do dado (X)');
ylabel('F(X)');
title('Função de Distribuição Acumulada (FDA)');
xticks(0:6); % Mostrar também o ponto inicial (0)
ylim([0 1.1]); % FDA vai de 0 a 1