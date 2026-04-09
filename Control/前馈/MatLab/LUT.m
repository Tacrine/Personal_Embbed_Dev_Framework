target = 100;
K_values = [0.001, 0.005, 0.01, 0.02, 0.05, 0.1, 0.5];
colors = lines(length(K_values));

input_range = linspace(-300, 500, 500);
error = target - input_range;
dt = input_range(2) - input_range(1);

figure('Position', [100, 100, 900, 600]);
subplot(1, 2, 1);
hold on;
for i = 1:length(K_values)
    output = K_values(i) * error.^3 * (1/target.^3);
    plot(input_range, output, 'LineWidth', 2, 'Color', colors(i,:), 'DisplayName', ['K=', num2str(K_values(i))]);
end
grid on;
xlabel('Input (输入值)', 'FontSize', 12);
ylabel('Output (输出值)', 'FontSize', 12);
title(['Feed-Forward输出: Target=', num2str(target)], 'FontSize', 14);
hold on;
plot([-300, 500], [0, 0], 'k--', 'LineWidth', 1);
plot([target, target], [get(gca, 'YLim')], 'r--', 'LineWidth', 1);
legend('Location', 'best');

subplot(1, 2, 2);
hold on;
for i = 1:length(K_values)
    output = K_values(i) * error.^3 * (1/target.^3);
    integral_output = cumsum(output) * dt;
    plot(input_range, integral_output, 'LineWidth', 2, 'Color', colors(i,:), 'DisplayName', ['K=', num2str(K_values(i))]);
end
grid on;
xlabel('Input (输入值)', 'FontSize', 12);
ylabel('Integral Output (积分输出)', 'FontSize', 12);
title(['积分量输出: Target=', num2str(target)], 'FontSize', 14);
hold on;
plot([-300, 500], [0, 0], 'k--', 'LineWidth', 1);
plot([target, target], [get(gca, 'YLim')], 'r--', 'LineWidth', 1);
legend('Location', 'best');

