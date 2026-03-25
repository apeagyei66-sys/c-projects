import time

# --- MINERAL DATA CONFIGURATION ---
# Densities (g/cm^3) and estimated market value per gram
MINERALS = {
    "Gold": {"density": 19.3, "value": 75.0},
    "Manganese": {"density": 7.2, "value": 0.15},
    "Bauxite": {"density": 2.5, "value": 0.05},
    "Waste": {"density": 2.6, "value": 0.0}
}

MARGIN_OF_ERROR = 0.5

def run_plant():
    print("--------------------------------------------------")
    print("    UMAT-SRID AUTOMATED MINERAL SORTING SYSTEM    ")
    print("--------------------------------------------------\n")

    try:
        count = int(input("Number of samples on belt: "))
    except ValueError:
        print("Error: Please enter a whole number.")
        return

    revenue = 0.0
    bins = {"Gold": 0, "Manganese": 0, "Bauxite": 0, "Waste": 0}

    for i in range(1, count + 1):
        print(f"\n--- Scanning Sample #{i} ---")
        time.sleep(0.5)

        try:
            m = float(input("  Mass (g): "))
            v = float(input("  Volume (cm^3): "))

            if m <= 0 or v <= 0:
                print("  [SYSTEM ERROR]: Invalid physics dimensions.")
                continue

            density = m / v
            print(f"  Calculated Density: {density:.2f} g/cm^3")

            found = "Waste"
            for name, data in MINERALS.items():
                if abs(density - data["density"]) <= MARGIN_OF_ERROR:
                    found = name
                    break

            if found == "Waste":
                print("  ACTION: Diverting to WASTE TAILINGS.")
                bins["Waste"] += 1
            else:
                print(f"  ACTION: Diverting to {found.upper()} RECOVERY.")
                bins[found] += 1
                revenue += (m * MINERALS[found]["value"])

        except ValueError:
            print("  [ERROR]: Input must be a number.")

    # --- END OF SHIFT REPORT ---
    print("\n" + "="*40)
    print("            SHIFT REPORT")
    print("="*40)
    print(f"Total Samples: {count}")
    print(f"Gold: {bins['Gold']} | Manganese: {bins['Manganese']} | Bauxite: {bins['Bauxite']}")
    print(f"Waste: {bins['Waste']}")
    print(f"TOTAL ESTIMATED REVENUE: ${revenue:,.2f}")
    print("="*40)

if name == "main":
    run_plant()