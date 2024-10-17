package lab9;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class ParticleSystem {
    private List<Integer> particles;

    public ParticleSystem() {
        this.particles = new ArrayList<>();
    }

    public void addParticle(int energy) {
        particles.add(energy);
    }

    public int simulateCollisions() {
        int totalEnergy = 0;

        while (particles.size() > 1) {
            int maxEnergyDiff = 0;
            int collisionIndex = -1;

            for (int i = 0; i < particles.size() - 1; i++) {
                int energyDiff = Math.abs(particles.get(i) - particles.get(i + 1));
                if (energyDiff > maxEnergyDiff) {
                    maxEnergyDiff = energyDiff;
                    collisionIndex = i;
                }
            }

            if (collisionIndex != -1) {
                totalEnergy += maxEnergyDiff;
                particles.remove(collisionIndex);
                particles.remove(collisionIndex);
            } else {
                break;
            }
        }

        return totalEnergy;
    }
}

public class LAB9NO9 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        ParticleSystem particleSystem = new ParticleSystem();

        for (int i = 0; i < N; i++) {
            int energy = scanner.nextInt();
            particleSystem.addParticle(energy);
        }

        int totalEnergy = particleSystem.simulateCollisions();
        System.out.println(totalEnergy);

        scanner.close();
    }
}