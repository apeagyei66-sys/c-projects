import customtkinter as ctk
import subprocess
import os
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt

# Professional Theme Settings
ctk.set_appearance_mode("dark")
ctk.set_default_color_theme("blue")

class UMaTBrakingSystem(ctk.CTk):
    def __init__(self):.  # FIXED: Double underscores here
        super().init()

        self.title("UMaT-SRID | Vehicle Safety Analysis Tool")
        self.geometry("1000x600")

        self.grid_columnconfigure(1, weight=1)
        self.grid_rowconfigure(0, weight=1)

        # --- SIDEBAR ---
        self.sidebar = ctk.CTkFrame(self, width=280, corner_radius=0)
        self.sidebar.grid(row=0, column=0, sticky="nsew")
        
        self.title_label = ctk.CTkLabel(self.sidebar, text="SYSTEM INPUTS", font=ctk.CTkFont(size=20, weight="bold"))
        self.title_label.pack(pady=30)

        self.mass_label = ctk.CTkLabel(self.sidebar, text="Vehicle Mass (kg):")
        self.mass_label.pack()
        self.mass_entry = ctk.CTkEntry(self.sidebar)
        self.mass_entry.insert(0, "1500")
        self.mass_entry.pack(pady=10, padx=20)

        self.speed_label = ctk.CTkLabel(self.sidebar, text="Initial Speed (km/h):")
        self.speed_label.pack()
        self.speed_entry = ctk.CTkEntry(self.sidebar)
        self.speed_entry.insert(0, "80")
        self.speed_entry.pack(pady=10, padx=20)

        self.road_label = ctk.CTkLabel(self.sidebar, text="Road Condition:")
        self.road_label.pack()
        self.road_option = ctk.CTkOptionMenu(self.sidebar, values=["Dry Asphalt (0.8)", "Wet Road (0.4)", "Icy Surface (0.1)"])
        self.road_option.pack(pady=10, padx=20)

        self.calc_btn = ctk.CTkButton(self.sidebar, text="RUN SIMULATION", fg_color="#1f6aa5", command=self.perform_calculation)
        self.calc_btn.pack(pady=40, padx=20)

        # --- MAIN DISPLAY ---
        self.main_display = ctk.CTkFrame(self)
        self.main_display.grid(row=0, column=1, padx=20, pady=20, sticky="nsew")

        self.result_title = ctk.CTkLabel(self.main_display, text="ANALYSIS DASHBOARD", font=ctk.CTkFont(size=22, weight="bold"))
        self.result_title.pack(pady=15)

        self.result_data = ctk.CTkLabel(self.main_display, text="Results will appear here...", font=ctk.CTkFont(size=16))
        self.result_data.pack(pady=10)

        self.fig, self.ax = plt.subplots(figsize=(6, 4), dpi=100)
        self.fig.patch.set_facecolor('#2b2b2b')
        self.canvas = FigureCanvasTkAgg(self.fig, master=self.main_display)
        self.canvas.get_tk_widget().pack(fill="both", expand=True, padx=20, pady=20)

    def perform_calculation(self):
        try:
            m = self.mass_entry.get()
            v = self.speed_entry.get()
            mu = self.road_option.get().split("(")[1].replace(")", "")

            # Path for Mac
            cpp_exe = os.path.join("..", "backend", "engine")
            
            output = subprocess.check_output([cpp_exe, m, v, mu])
            dist, force = output.decode("utf-8").strip().split(",")

            self.result_data.configure(text=f"STOPPING DISTANCE: {dist} m   |   BRAKING FORCE: {force} N", text_color="#2ecc71")

            self.ax.clear()
            self.ax.set_facecolor('#1e1e1e') 
            self.ax.tick_params(colors='white')
            
            speeds = [20, 40, 60, 80, 100, 120, 140]
            distances = []
            for s in speeds:
                p = subprocess.check_output([cpp_exe, m, str(s), mu])
                distances.append(float(p.decode("utf-8").strip().split(",")[0]))

            self.ax.plot(speeds, distances, color='#3498db', marker='o', linewidth=2)
            self.ax.set_title("Braking Distance Curve", color="white", fontsize=14)
            self.ax.set_xlabel("Speed (km/h)", color="white")
            self.ax.set_ylabel("Distance (m)", color="white")
            self.ax.grid(True, linestyle='--', alpha=0.3)
            self.canvas.draw()

        except Exception as e:
            self.result_data.configure(text=f"Error: {e}", text_color="red")


if __name__ == "__main__":. # FIXED: Double underscores here
    app = UMaTBrakingSystem()
    app.mainloop()~
