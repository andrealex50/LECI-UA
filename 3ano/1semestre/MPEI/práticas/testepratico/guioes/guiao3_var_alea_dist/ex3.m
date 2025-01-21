% a)
n = 4;
N = 100000;
p = 0.5;
x = 0:4;

% sendo 0 coroa e 1 cara

function pX = funcaoMassa(N,n,k,p)
    lancamentos = rand(n,N) < p;
    sucessos = sum(lancamentos) == k;
    pX = sum(sucessos) / N;
end

pX = zeros(1,5);

for i = 1:5
    k = i-1;
    pX(i) = funcaoMassa(N,n,k,p);
end

figure;
stem(x,pX);
xlabel("nº lançamento");
ylabel("probabilidade");
grid on;
