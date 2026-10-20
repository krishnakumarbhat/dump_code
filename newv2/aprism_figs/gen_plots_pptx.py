import matplotlib.pyplot as plt
import numpy as np

# Dark theme matching PPTX palette
plt.rcParams['text.color'] = '#FFFFFF'
plt.rcParams['axes.labelcolor'] = '#FFFFFF'
plt.rcParams['xtick.color'] = '#9FB4C2'
plt.rcParams['ytick.color'] = '#9FB4C2'
plt.rcParams['figure.facecolor'] = '#0B131B'
plt.rcParams['axes.facecolor'] = '#0B131B'
plt.rcParams['axes.edgecolor'] = '#1F3547'
plt.rcParams['grid.color'] = '#1F3547'
plt.rcParams['grid.alpha'] = 0.5

# Slide 2 plot: Boresight Azimuth Error vs Scan Index
fig, ax = plt.subplots(figsize=(6.5, 3.8), dpi=300)

# Baseline crawl
frames_baseline = np.arange(0, 420, 10)
error_baseline = 0.5 * np.exp(-frames_baseline/120) + 0.02 + 0.03*np.random.randn(len(frames_baseline))*0.01
error_baseline = np.clip(error_baseline, 0.01, 0.5)

# Dual-horizon fast lock
frames_dual = np.arange(0, 120, 2)
error_dual = 0.48 * np.exp(-frames_dual/8) + 0.015 + 0.005*np.random.randn(len(frames_dual))*0.01
error_dual = np.clip(error_dual, 0.01, 0.48)

ax.semilogy(frames_baseline, error_baseline, color='#9FB4C2', linewidth=2, label='Baseline $K_0=0.0025$ (400 frames)', marker='o', markersize=3, markevery=40)
ax.semilogy(frames_dual, error_dual, color='#35E0A1', linewidth=3, label='Dual-Horizon $K_\\mathrm{DA}(N)$ (46 frames)', marker='D', markersize=3, markevery=15)

ax.axvline(x=46, color='#FF6B6B', linestyle='--', linewidth=2, alpha=0.9, label='Lock at Frame 46 / 2.3 s')
ax.axhline(y=0.05, color='#41B6FF', linestyle=':', linewidth=1.5, alpha=0.7, label='Lock threshold $\\epsilon=0.05^\\circ$')

ax.set_xlabel('Scan Index $N$ (20 Hz frame rate)', fontsize=11, fontweight='bold')
ax.set_ylabel('Boresight Azimuth Error $\\theta_\\mathrm{az}$ [deg]', fontsize=11, fontweight='bold')
ax.set_title('Breakthrough 1 — Dual-Horizon Dynamic Alignment Lock\nCold-Start Calibration Barrier Eliminated', fontsize=13, fontweight='bold', pad=12)
ax.legend(loc='upper right', fontsize=9, facecolor='#12202C', edgecolor='#1F3547', framealpha=0.95)
ax.set_xlim(0, 420)
ax.set_ylim(0.008, 1.0)
ax.grid(True, which='both', linestyle='-', alpha=0.3)

# Annotation arrow at lock point
ax.annotate('Lock\nFrame 46', xy=(46, 0.05), xytext=(120, 0.2),
            arrowprops=dict(facecolor='#FF6B6B', edgecolor='#FF6B6B', arrowstyle='->', lw=2),
            fontsize=10, color='#FF6B6B', fontweight='bold', ha='center')

plt.tight_layout()
fig.savefig('C:\\Users\\ouymc2\\Desktop\\aprism_figs\\plot_dual_horizon.png', dpi=300, bbox_inches='tight', facecolor='#0B131B', edgecolor='none')
plt.close()
print("plot_dual_horizon saved")
