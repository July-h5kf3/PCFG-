data = load('result.out');
x = 1:length(data);
scatter(x,data);
title('PCFG Password Crack');
xlabel('猜测次数');
ylabel('成功次数');
